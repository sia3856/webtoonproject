#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->login); // 첫화면을 로그인 화면으로 출력
    this->setWindowTitle("민호의 비밀서재"); // 프로그램 이름설정

    m_socket = new QTcpSocket(this);
    m_socket->connectToHost(QHostAddress::LocalHost,8080);
    if(m_socket->waitForConnected())
    {
        // 연결 성공시 출력
        ui->statusbar->showMessage("Connected to Server");
    }
    else
    {
        QMessageBox::critical(this,"QTCPClient", QString("The following error occurred: %1.").arg(m_socket->errorString()));
        exit(EXIT_FAILURE);
    }
    connect(m_socket, &QTcpSocket::readyRead,
            this,     &MainWindow::slot_readSocket);

    // [ex.02.1.3]
    // signal_newMessage 시그널이 발생하면 (socket read 가 아닌, MainWindow 시그널)
    // slot_displayMessage 실행하여 UI에 출력
    // connect(this, &MainWindow::signal_newMessage,
    //         this, &MainWindow::slot_displayMessage);

    // [ex.02.1.4]
    // 연결된 소켓과 연결이 해제되면,
    // 이 객체의(MainWindow) slot_discardSocket 슬롯 함수 실행하여 처리
    connect(m_socket, &QTcpSocket::disconnected,
            this,     &MainWindow::slot_discardSocket);

    // [ex.02.1.4]
    // 연결된 소켓에 문제가 발생하면,
    // 이 객체의(MainWindow) slot_displayError 슬롯 함수 실행하여 처리
    connect(m_socket, &QAbstractSocket::errorOccurred,
            this,     &MainWindow::slot_displayError);

}

MainWindow::~MainWindow()
{
    if(m_socket->isOpen())
        m_socket->close();
    delete ui;
}
// 서버에서 연결이 끊어지면 상태바
void MainWindow::slot_discardSocket()
{
    m_socket->deleteLater();
    m_socket=nullptr;

    ui->statusbar->showMessage("Disconnected!");
}

// 연결된 소켓에서 에러 발생하면 출력
void MainWindow::slot_displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, "QTCPClient", "The host was not found. Please check the host name and port settings.");
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, "QTCPClient", "The connection was refused by the peer. Make sure QTCPServer is running, and check that the host name and port settings are correct.");
        break;
    default:
        QMessageBox::information(this, "QTCPClient", QString("The following error occurred: %1.").arg(m_socket->errorString()));
        break;
    }
}

void MainWindow::slot_readSocket()
{
    // QByteArray 타입의 buffer를 만들고
    QByteArray buffer;

    // 서버에 연결된 socket을 stream으로 연결한다.
    QDataStream socketStream(m_socket);
    socketStream.setVersion(QDataStream::Qt_5_15);

    // stream으로 데이터를 읽어들이고, buffer로 넘기면
    socketStream.startTransaction();
    socketStream >> buffer;

    // stream startTransaction 실행 문제시 에러 표시 후 함수 종료
    if(!socketStream.commitTransaction())
    {
        QString message = QString("%1 :: Waiting for more data to come..").arg(m_socket->socketDescriptor());
        emit signal_newMessage(message);
        return;
    }

    // client 에서 보낸 payload(순수한 데이터, 전달 메시지)를
    // buffer에서 처음 128 byte 부분만 읽어들여서 header 에 담고 fileType을 찾는다.
    QString header = buffer.mid(0,128);
    QString fileType = header.split(",")[0].split(":")[1];


    // buffer의 128 byte 이후 부분을
    buffer = buffer.mid(128);

    // fileType이 attachment 라면 파일 수신 로직을 실행하고
    // fileType이 message 라면 문장 수신 로직을 실핸한다.

    if(fileType=="attachment")
    {
        // 파일 전송은, 1)저장될 파일 이름, 2) 파일 확장자 3) 파일 크기 정보가 필요하다.
        QString fileName = header.split(",")[1].split(":")[1];
        QString ext = fileName.split(".")[1];
        QString size = header.split(",")[2].split(":")[1].split(";")[0];
        QPixmap *buf = new QPixmap(); //버퍼로 사용할 QPixmap 선언


        buf->loadFromData(buffer);
        ui->lbl->setPixmap(*buf);


        // int newWidth = 430;
        // QPixmap scaledPixmap = buf->scaled(newWidth, buf->height() * newWidth / buf->width(), Qt::KeepAspectRatio);
        // ui->lbl->setPixmap(scaledPixmap);
    }
    else if(fileType=="message")
    {
        // 전송된 메시지를 출력한다.
        QString message = QString("%1 :: %2").arg(m_socket->socketDescriptor()).arg(QString::fromStdString(buffer.toStdString()));
        emit signal_newMessage(message);
    }
}



void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->login);
}


void MainWindow::on_f_idbtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->find_id);
}


void MainWindow::on_f_pwbtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->find_pw);
}


void MainWindow::on_reg_gobtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->reg_page);
}


void MainWindow::on_loginbtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->main_page);
}


void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    if(index == 0)
    {
        ui->statusbar->showMessage("전체 메뉴");
    }
    else if(index == 1)
    {
        ui->statusbar->showMessage("작가별");
    }
}

