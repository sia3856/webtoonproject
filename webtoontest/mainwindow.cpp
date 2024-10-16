#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->login); // 첫화면을 로그인 화면으로 출력
    this->setWindowTitle("복이의 비밀서재"); // 프로그램 이름설정
    overpn_cnt = 0;
    overid_cnt = 0;

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
    connect(m_socket, &QTcpSocket::readyRead, this, &MainWindow::slot_readSocket);

    // [ex.02.1.3]
    // signal_newMessage 시그널이 발생하면 (socket read 가 아닌, MainWindow 시그널)
    // slot_displayMessage 실행하여 UI에 출력
    connect(this, &MainWindow::signal_newMessage, this, &MainWindow::slot_displayMessage);

    // [ex.02.1.4]
    // 연결된 소켓과 연결이 해제되면,
    // 이 객체의(MainWindow) slot_discardSocket 슬롯 함수 실행하여 처리
    connect(m_socket, &QTcpSocket::disconnected, this, &MainWindow::slot_discardSocket);

    // [ex.02.1.4]
    // 연결된 소켓에 문제가 발생하면,
    // 이 객체의(MainWindow) slot_displayError 슬롯 함수 실행하여 처리
    connect(m_socket, &QAbstractSocket::errorOccurred, this, &MainWindow::slot_displayError);

    //테이블을 눌렀을떄
    connect(ui->test_table, &QTableView::clicked, this, &MainWindow::onTableCellClicked);

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
        //emit signal_newMessage(message);
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
        QString message = QString("%1").arg(QString::fromStdString(buffer.toStdString()));
        emit signal_newMessage(message);
    }
    else if(fileType =="opnfail")
    {
        ui->ovl_pn->setText("중복된 전화번호");
        ui->ovl_pn->setStyleSheet("color: red;");
        overpn_cnt = 0;

    }
    else if(fileType == "opnsuc")
    {
        ui->ovl_pn->setText("사용가능한 전화번호");
        ui->ovl_pn->setStyleSheet("color: green;");
        overpn_cnt = 1;
    }
    else if(fileType =="oidfail")
    {
        ui->ovl_id->setText("중복된 아이디");
        ui->ovl_id->setStyleSheet("color: red;");
        overid_cnt = 0;

    }
    else if(fileType == "oidsuc")
        {
            ui->ovl_id->setText("사용가능한 아이디");
            ui->ovl_id->setStyleSheet("color: green;");
            overid_cnt = 1;
        }


}

void MainWindow::slot_displayMessage(const QString& str)
{
    ui->test_bro->append(str);
    QString rstr = str;

    //rstr.remove(QRegularExpression("^\\d+ :: "));
    QStringList rows = rstr.split("\n");

    QStandardItemModel *model = new QStandardItemModel();
    model->setColumnCount(2); // 제목과 작가 두 열 설정
    model->setHorizontalHeaderLabels(QStringList() << "제목" << "작가");

    for (const QString &row : rows) {
        QStringList columns = row.split("/");
        if (columns.size() == 2) {
            QList<QStandardItem*> items;
            items << new QStandardItem(columns[0].trimmed())
                  << new QStandardItem(columns[1].trimmed());
            model->appendRow(items);
        }
    }

    // QTableView 생성 및 모델 설정

    ui->test_table->setModel(model);

    // 열 너비 자동 조정
    ui->test_table->resizeColumnsToContents();

    ui->test_table->show();


}


void MainWindow::onTableCellClicked(const QModelIndex &index)
{
    int row = index.row();
    int column = index.column();
    QVariant data = index.data();


    // 여기서 원하는 동작 수행
    qDebug() << "Clicked cell:" << row << column<< data.toString();
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


void MainWindow::on_reg_btn_clicked()
{

    QString r_name = ui->reg_name->text();
    QString r_pn = ui->reg_pn->text();
    QString r_id = ui->reg_id->text();
    QString r_pw = ui->reg_pw->text();
    if(overpn_cnt !=1 && overid_cnt !=1)
    {
        QMessageBox::about(this,"오류","아이디와 전화번호 중복을 확인하세요");
    }
    else if(overid_cnt !=1)
    {
        QMessageBox::about(this,"오류","아이디 중복을 확인하세요");
    }
    else if(overpn_cnt !=1)
    {
        QMessageBox::about(this,"오류","아이디 중복을 확인하세요");
    }
    else if(r_name.isEmpty()||r_pn.isEmpty()||r_id.isEmpty()||r_pw.isEmpty())
    {
        QMessageBox::about(this,"오류","모든 정보를 입력하시오");
    }
    else
    {
        if(m_socket)
        {
            if(m_socket->isOpen())
            {
                // ui에서 입력할 message를 가져와
                QString r_res = r_name +","+r_pn+","+r_id+","+r_pw;
                qDebug() << r_res;
                // stream으로 보내는데
                QDataStream socketStream(m_socket);
                socketStream.setVersion(QDataStream::Qt_5_15);

                // 헤더 부분에 fileType을 message로 설정한다.
                QByteArray header;
                header.prepend(QString("fileType:reg,fileName:null,fileSize:;").toUtf8());
                header.resize(128);

                // message 인코딩 설정하고, QByteArray에 할당하고
                QByteArray byteArray = r_res.toUtf8();
                // header 정보를 앞에 넣어준다.
                byteArray.prepend(header);

                // stream으로 byteArray 정보 전송
                socketStream << byteArray;

                // 메시지 입력창 리셋
                ui->reg_name->clear();
            }
            else
                QMessageBox::critical(this,"QTCPClient","Socket doesn't seem to be opened");
        }
        else
            QMessageBox::critical(this,"QTCPClient","Not connected");
    }

}


void MainWindow::on_pn_ckbtn_clicked()
{

    if(m_socket)
    {
        if(m_socket->isOpen())
        {
            QString rr_pn = ui->reg_pn->text();


            QDataStream socketStream(m_socket);
            socketStream.setVersion(QDataStream::Qt_5_15);

            // 헤더 부분에 fileType을 message로 설정한다.
            QByteArray header;
            header.prepend(QString("fileType:overpn,fileName:null,fileSize:;").toUtf8());
            header.resize(128);

            // message 인코딩 설정하고, QByteArray에 할당하고
            QByteArray byteArray = rr_pn.toUtf8();
            // header 정보를 앞에 넣어준다.
            byteArray.prepend(header);
            qDebug() << byteArray;
            // stream으로 byteArray 정보 전송
            socketStream << byteArray;
        }
        else
            QMessageBox::critical(this,"QTCPClient","Socket doesn't seem to be opened");
    }
    else
        QMessageBox::critical(this,"QTCPClient","Not connected");

}




void MainWindow::on_id_ckbtn_clicked()
{
    if(m_socket)
    {
        if(m_socket->isOpen())
        {
            QString rr_id = ui->reg_id->text();


            QDataStream socketStream(m_socket);
            socketStream.setVersion(QDataStream::Qt_5_15);

            // 헤더 부분에 fileType을 message로 설정한다.
            QByteArray header;
            header.prepend(QString("fileType:overid,fileName:null,fileSize:;").toUtf8());
            header.resize(128);

            // message 인코딩 설정하고, QByteArray에 할당하고
            QByteArray byteArray = rr_id.toUtf8();
            // header 정보를 앞에 넣어준다.
            byteArray.prepend(header);
            qDebug() << byteArray;
            // stream으로 byteArray 정보 전송
            socketStream << byteArray;
        }
        else
            QMessageBox::critical(this,"QTCPClient","Socket doesn't seem to be opened");
    }
    else
        QMessageBox::critical(this,"QTCPClient","Not connected");
}

