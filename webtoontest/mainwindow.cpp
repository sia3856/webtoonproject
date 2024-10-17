#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentWidget(ui->login); // 첫화면을 로그인 화면으로 출력
    this->setWindowTitle("민호의 비밀서재"); // 프로그램 이름설정
    ui->in_id->setPlaceholderText("아이디를 입력하시오");
    ui->in_pw->setPlaceholderText("비밀번호를 입력하시오");

    ui->fp_inid->setPlaceholderText("아이디를 입력하시오");
    ui->fp_inpn->setPlaceholderText("전화번호를 입력하시오");

    ui->reg_pn->setPlaceholderText("전화번호를 입력하시오");
    ui->reg_name->setPlaceholderText("이름을 입력하시오");
    ui->reg_pw->setPlaceholderText("비밀번호를 입력하시오");
    ui->reg_id->setPlaceholderText("아이디를 입력하시오");

    ui->f_inname->setPlaceholderText("이름을 입력하시오");
    ui->f_inpn->setPlaceholderText("전화번호를 입력하시오");

    overpn_cnt = 0;
    overid_cnt = 0;
    intro_cnt = 0;

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
    connect(ui->test_table, &QTableView::doubleClicked, this, &MainWindow::go_to_list);

    connect(ui->reg_id, &QLineEdit::textChanged, this, &MainWindow::id_text_changed);
    connect(ui->reg_pn, &QLineEdit::textChanged, this, &MainWindow::pn_text_changed);

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
    while(m_socket->bytesAvailable())
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

        if(fileType=="attachment")// 나중에 지울꺼
        {
            // 파일 전송은, 1)저장될 파일 이름, 2) 파일 확장자 3) 파일 크기 정보가 필요하다.
            QString fileName = header.split(",")[1].split(":")[1];
            QPixmap buf ; //버퍼로 사용할 QPixmap 선언
            // buf.loadFromData(buffer);
            // // int newWidth = 100;
            // // QPixmap scaledPixmap = buf.scaled(newWidth, buf.height() * newWidth / buf.width(), Qt::KeepAspectRatio);

            // ui->lbl->setPixmap(buf);
            // // ui->lbl->setPixmap(scaledPixmap);
        }
        // else if(fileType=="message")
        // {
        //     // 전송된 메시지를 출력한다.
        //     QString message = QString("%1").arg(QString::fromStdString(buffer.toStdString()));
        //     emit signal_newMessage(message);
        // }
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
        else if(fileType == "loginsuc")
        {
            QMessageBox::information(this," ","로그인성공");
            ui->stackedWidget->setCurrentWidget(ui->main_page);
            ui->in_id->clear();
            ui->in_pw->clear();
            ui->pushButton->setText("로그아웃");
            if(intro_cnt == 0)
            {
                s_sendmsg("intro","");
                intro_cnt = 1;
            }
        }
        else if(fileType == "loginfail")
        {
            QMessageBox::critical(this,"로그인실패","아이디 혹은 비밀번호가 맞지않습니다.");
            ui->in_id->clear();
            ui->in_pw->clear();
        }
        else if(fileType == "findsuc")
        {
            QString masg = "회원님의 아이디는 : "+buffer;
            QMessageBox::information(this,"찾기 성공",masg);
            ui->f_inname->clear();
            ui->f_inpn->clear();
            ui->stackedWidget->setCurrentWidget(ui->login);
        }
        else if(fileType == "findfail")
        {
            QMessageBox::critical(this,"오류","존재 하지 않는 유저입니다.");
            ui->f_inname->clear();
            ui->f_inpn->clear();
        }
        else if(fileType == "ffindsuc")
        {
            QString masg = "회원님의 비밀번호는 : "+buffer;
            QMessageBox::information(this,"찾기 성공",masg);
            ui->fp_inid->clear();
            ui->fp_inpn->clear();
            ui->stackedWidget->setCurrentWidget(ui->login);
        }
        else if(fileType == "ffindfail")
        {
            QMessageBox::critical(this,"오류","존재 하지 않는 유저입니다.");
            ui->fp_inid->clear();
            ui->fp_inpn->clear();
        }
        else if(fileType == "r_intro")
        {
            //QString message = QString("%1").arg(QString::fromStdString(buffer.toStdString()));
            QString message = buffer;
            emit signal_newMessage(message);
        }
        else if(fileType=="rogosend")
        {
            // 파일 전송은, 1)저장될 파일 이름, 2) 파일 확장자 3) 파일 크기 정보가 필요하다.
            QPixmap buf ; //버퍼로 사용할 QPixmap 선언
            buf.loadFromData(buffer);
            int newWidth = 250;
            QPixmap scaledPixmap = buf.scaled(newWidth, buf.height() * newWidth / buf.width(), Qt::KeepAspectRatio);

            //ui->lbl->setPixmap(buf);
            ui->openbtn->setIcon(scaledPixmap);
            ui->openbtn->setIconSize(scaledPixmap.rect().size());
            ui->openbtn2->setIcon(scaledPixmap);
            ui->openbtn2->setIconSize(scaledPixmap.rect().size());
            //ui->lbl->setPixmap(scaledPixmap);
            //ui->toonlbl->setPixmap(scaledPixmap2);
        }
        else if(fileType == "listviewres")
        {
            QString sstr = buffer;
            qDebug() << sstr;
            QStringList rows = sstr.split("\n");  // \n 기준으로 자름
            QStandardItemModel *viewmodel = new QStandardItemModel();
            viewmodel->setColumnCount(3); // 칼럼 갯수 생성
            viewmodel->setHorizontalHeaderLabels(QStringList() << "제목" << "작가"<<"회차"); // 칼럼명 지정
            bool hasData = false;

            for (const QString &row : rows) {
                QStringList columns = row.split("/");
                if (columns.size() == 3) {
                    QList<QStandardItem*> viewitems;
                    viewitems << new QStandardItem(columns[0].trimmed()) << new QStandardItem(columns[1].trimmed()) << new QStandardItem(columns[2].trimmed());
                    viewmodel->appendRow(viewitems);
                    hasData = true;
                }
            }
            if (!hasData) {
                QList<QStandardItem*> noDataItems;
                noDataItems << new QStandardItem("데이터가 없습니다") << new QStandardItem("ㅠㅠㅠ") << new QStandardItem("빠른 시일내 업데이트 하겠습니다.");
                viewmodel->appendRow(noDataItems);
            }
            // QTableView 생성 및 모델 설정
            ui->listviwer->setModel(viewmodel);
            // 열 너비 자동 조정
            ui->listviwer->resizeColumnsToContents();
            ui->listviwer->show();

        }
    }

}

void MainWindow::slot_displayMessage(const QString& str)
{
    QStringList rows = str.split("\n");  // \n 기준으로 자름
    //QStandardItemModel *model = new QStandardItemModel();
    model->setColumnCount(3); // 칼럼 갯수 생성
    model->setHorizontalHeaderLabels(QStringList() << "제목" << "작가"<<"연재요일"); // 칼럼명 지정

    for (const QString &row : rows) {
        QStringList columns = row.split("/");
        if (columns.size() == 3) {
            QList<QStandardItem*> items;
            items << new QStandardItem(columns[0].trimmed()) << new QStandardItem(columns[1].trimmed()) << new QStandardItem(columns[2].trimmed());
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
    rrow = index.row();
    ccolumn = index.column();
    //QVariant data = index.data();
    rrow += 1;
    QString r_row = QString::number(rrow);
    s_sendmsg("sntst",r_row);
    int cccolumn = 0;

    rdata = index.sibling(rrow-1,cccolumn).data().toString();


    // 여기서 원하는 동작 수행
    qDebug() << "Clicked cell:" << r_row << ccolumn<< rdata;
}


void MainWindow::on_pushButton_clicked()
{
    // ui->lbl->clear();
    // ui->in_id->clear();
    // ui->in_pw->clear();
    // ui->fp_inid->clear();
    // ui->fp_inpn->clear();
    // ui->reg_id->clear();
    // ui->reg_name->clear();
    // ui->reg_pn->clear();
    // ui->reg_pw->clear();
    // ui->ovl_id->setText("중복 여부를 확인하세요.");
    // ui->ovl_pn->setText("중복 여부를 확인하세요.");
    // ui->ovl_id->setStyleSheet("color: black;");
    // ui->ovl_pn->setStyleSheet("color: black;");
    // ui->f_inname->clear();
    // ui->f_inpn->clear();
    if(ui->pushButton->text()== "로그아웃")
    {
        ui->pushButton->setText("뒤로가기");
        QMessageBox::information(this,"로그아웃","로그아웃을 합니다.");
    }
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
void MainWindow::go_to_list()
{
    qDebug() << "Clicked cell:" <<rdata;
    s_sendmsg("listview",rdata);

    ui->stackedWidget->setCurrentWidget(ui->list_view);
    //rrow +=1;
    //QModelIndex index = ui->test_table->model()->index(rrow, ccolumn);
    //ui->test_table->hide();
    //emit ui->test_table->clicked(index);
    //ui->lbl->clear();

    // ui->listviwer->setModel(model);
    // // 열 너비 자동 조정
    // ui->listviwer->resizeColumnsToContents();
    // ui->listviwer->show();
}



//로그인 버튼
void MainWindow::on_loginbtn_clicked()
{
    QString l_id = ui->in_id->text();
    QString l_pw = ui->in_pw->text();
    QString r_res = l_id +","+l_pw;
    s_sendmsg("login",r_res);
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

//회원가입 버튼
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
        QString r_res = r_name +","+r_pn+","+r_id+","+r_pw;
        s_sendmsg("reg",r_res);
        QMessageBox::information(this," ","회원가입 성공");
        ui->stackedWidget->setCurrentWidget(ui->login);
    }

}

//전화번호 중복 체크
void MainWindow::on_pn_ckbtn_clicked()
{
    QString rr_pn = ui->reg_pn->text();
    s_sendmsg("overpn",rr_pn);
}

void MainWindow::id_text_changed()
{
    ui->ovl_id->setText("중복 여부를 다시 확인하세요.");
    ui->ovl_id->setStyleSheet("color: black;");
    overid_cnt = 0;
}

void MainWindow::pn_text_changed()
{
    ui->ovl_pn->setText("중복 여부를 다시 확인하세요.");
    ui->ovl_pn->setStyleSheet("color: black;");
    overpn_cnt = 0;
}

//아이디 중복 체크
void MainWindow::on_id_ckbtn_clicked()
{
    QString rr_id = ui->reg_id->text();
    s_sendmsg("overid",rr_id);
}

//요청문 명령어 함수
void MainWindow::s_sendmsg(QString req, QString msg)
{
    if(m_socket)
    {
        if(m_socket->isOpen())
        {
            // ui에서 입력할 message를 가져와

            // stream으로 보내는데
            QDataStream socketStream(m_socket);
            socketStream.setVersion(QDataStream::Qt_5_15);

            // 헤더 부분에 fileType을 message로 설정한다.
            QByteArray header;
            header.prepend(QString("fileType:%1,").arg(req).toUtf8());
            header.resize(128);

            // message 인코딩 설정하고, QByteArray에 할당하고
            QByteArray byteArray = msg.toUtf8();
            // header 정보를 앞에 넣어준다.
            byteArray.prepend(header);

            // stream으로 byteArray 정보 전송
            socketStream << byteArray;

            // 메시지 입력창 리셋
        }
        else
            QMessageBox::critical(this,"QTCPClient","Socket doesn't seem to be opened");
    }
    else
        QMessageBox::critical(this,"QTCPClient","Not connected");
}


void MainWindow::on_f_btn_clicked()
{
    QString fi_name = ui->f_inname->text();
    QString fi_pn = ui->f_inpn->text();
    QString r_msg = fi_name + "," +fi_pn;
    s_sendmsg("findid",r_msg);
}


void MainWindow::on_fp_btn_clicked()
{
    QString fp_name = ui->fp_inid->text();
    QString fp_pn = ui->fp_inpn->text();
    QString r_msg = fp_name + "," +fp_pn;
    s_sendmsg("findpw",r_msg);
}

void MainWindow::on_openbtn_clicked()
{
    if (!ui->openbtn->icon().isNull()) {
        // 아이콘이 있을 경우 go_to_list() 함수 실행
        go_to_list();
    } else {
        QMessageBox::critical(this,"오류","웹툰을 선택해주세요.");
    }


    //go_to_list();
}

