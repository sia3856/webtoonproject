/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QGridLayout *gridLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *login;
    QGridLayout *gridLayout_3;
    QFrame *frame;
    QGridLayout *gridLayout_4;
    QPushButton *reg_gobtn;
    QLineEdit *in_id;
    QPushButton *loginbtn;
    QSpacerItem *horizontalSpacer;
    QLabel *id_label;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *in_pw;
    QLabel *pw_label;
    QPushButton *f_idbtn;
    QSpacerItem *verticalSpacer_2;
    QPushButton *f_pwbtn;
    QTextEdit *login_log;
    QLabel *lbl;
    QWidget *find_pw;
    QGridLayout *gridLayout_8;
    QFrame *frame_4;
    QGridLayout *gridLayout_9;
    QTextEdit *find_log_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *fp_idlb;
    QLineEdit *fp_inid;
    QLabel *fp_pnlb;
    QLineEdit *fp_inpn;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *fp_btn;
    QSpacerItem *verticalSpacer;
    QWidget *reg_page;
    QGridLayout *gridLayout;
    QFrame *frame_2;
    QGridLayout *gridLayout_5;
    QTextEdit *reg_log;
    QLabel *reg_nalb;
    QLineEdit *reg_name;
    QSpacerItem *horizontalSpacer_7;
    QLabel *reg_pnlb;
    QLineEdit *reg_pn;
    QPushButton *pn_ckbtn;
    QSpacerItem *horizontalSpacer_8;
    QLabel *reg_idlb;
    QLineEdit *reg_id;
    QPushButton *id_ckbtn;
    QLabel *reg_pwlb;
    QLineEdit *reg_pw;
    QPushButton *reg_btn;
    QSpacerItem *verticalSpacer_4;
    QWidget *main_page;
    QGridLayout *gridLayout_10;
    QFrame *frame_5;
    QGridLayout *gridLayout_12;
    QTextEdit *reg_log_2;
    QTabWidget *tabWidget;
    QWidget *all_tab;
    QGridLayout *gridLayout_11;
    QTableView *tableView;
    QWidget *author_tab;
    QListView *listView;
    QWidget *find_id;
    QGridLayout *gridLayout_7;
    QFrame *frame_3;
    QGridLayout *gridLayout_6;
    QTextEdit *find_log;
    QSpacerItem *horizontalSpacer_5;
    QLabel *f_nmlb;
    QLineEdit *f_inname;
    QSpacerItem *horizontalSpacer_6;
    QLabel *f_pnlb;
    QLineEdit *f_inpn;
    QSpacerItem *verticalSpacer_3;
    QPushButton *f_btn;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(744, 633);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        textEdit->setMaximumSize(QSize(16777215, 60));
        textEdit->setTabletTracking(false);
        textEdit->setAutoFillBackground(false);
        textEdit->setStyleSheet(QString::fromUtf8("border: none;\n"
""));

        verticalLayout->addWidget(textEdit);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        login = new QWidget();
        login->setObjectName("login");
        gridLayout_3 = new QGridLayout(login);
        gridLayout_3->setObjectName("gridLayout_3");
        frame = new QFrame(login);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_4 = new QGridLayout(frame);
        gridLayout_4->setObjectName("gridLayout_4");
        reg_gobtn = new QPushButton(frame);
        reg_gobtn->setObjectName("reg_gobtn");
        reg_gobtn->setMaximumSize(QSize(150, 16777215));

        gridLayout_4->addWidget(reg_gobtn, 3, 4, 1, 1);

        in_id = new QLineEdit(frame);
        in_id->setObjectName("in_id");

        gridLayout_4->addWidget(in_id, 1, 2, 1, 3);

        loginbtn = new QPushButton(frame);
        loginbtn->setObjectName("loginbtn");
        loginbtn->setMaximumSize(QSize(16777215, 100));

        gridLayout_4->addWidget(loginbtn, 1, 5, 2, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 1, 0, 2, 1);

        id_label = new QLabel(frame);
        id_label->setObjectName("id_label");

        gridLayout_4->addWidget(id_label, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 1, 6, 2, 1);

        in_pw = new QLineEdit(frame);
        in_pw->setObjectName("in_pw");

        gridLayout_4->addWidget(in_pw, 2, 2, 1, 3);

        pw_label = new QLabel(frame);
        pw_label->setObjectName("pw_label");

        gridLayout_4->addWidget(pw_label, 2, 1, 1, 1);

        f_idbtn = new QPushButton(frame);
        f_idbtn->setObjectName("f_idbtn");
        f_idbtn->setMaximumSize(QSize(150, 16777215));

        gridLayout_4->addWidget(f_idbtn, 3, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 4, 2, 1, 3);

        f_pwbtn = new QPushButton(frame);
        f_pwbtn->setObjectName("f_pwbtn");
        f_pwbtn->setMaximumSize(QSize(150, 16777215));

        gridLayout_4->addWidget(f_pwbtn, 3, 3, 1, 1);

        login_log = new QTextEdit(frame);
        login_log->setObjectName("login_log");
        login_log->setMaximumSize(QSize(16777215, 300));
        login_log->setStyleSheet(QString::fromUtf8("border: none;\n"
""));
        login_log->setReadOnly(true);

        gridLayout_4->addWidget(login_log, 0, 1, 1, 5);

        lbl = new QLabel(frame);
        lbl->setObjectName("lbl");

        gridLayout_4->addWidget(lbl, 0, 0, 1, 1);


        gridLayout_3->addWidget(frame, 0, 0, 1, 1);

        stackedWidget->addWidget(login);
        find_pw = new QWidget();
        find_pw->setObjectName("find_pw");
        gridLayout_8 = new QGridLayout(find_pw);
        gridLayout_8->setObjectName("gridLayout_8");
        frame_4 = new QFrame(find_pw);
        frame_4->setObjectName("frame_4");
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_9 = new QGridLayout(frame_4);
        gridLayout_9->setObjectName("gridLayout_9");
        find_log_2 = new QTextEdit(frame_4);
        find_log_2->setObjectName("find_log_2");
        find_log_2->setMaximumSize(QSize(16777215, 300));
        find_log_2->setStyleSheet(QString::fromUtf8("border: none;\n"
""));
        find_log_2->setReadOnly(true);

        gridLayout_9->addWidget(find_log_2, 0, 1, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(201, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        fp_idlb = new QLabel(frame_4);
        fp_idlb->setObjectName("fp_idlb");

        gridLayout_9->addWidget(fp_idlb, 1, 1, 1, 1);

        fp_inid = new QLineEdit(frame_4);
        fp_inid->setObjectName("fp_inid");

        gridLayout_9->addWidget(fp_inid, 1, 2, 1, 1);

        fp_pnlb = new QLabel(frame_4);
        fp_pnlb->setObjectName("fp_pnlb");

        gridLayout_9->addWidget(fp_pnlb, 2, 1, 1, 1);

        fp_inpn = new QLineEdit(frame_4);
        fp_inpn->setObjectName("fp_inpn");

        gridLayout_9->addWidget(fp_inpn, 2, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(201, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_4, 2, 3, 1, 1);

        fp_btn = new QPushButton(frame_4);
        fp_btn->setObjectName("fp_btn");

        gridLayout_9->addWidget(fp_btn, 3, 1, 1, 2);

        verticalSpacer = new QSpacerItem(20, 130, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_9->addItem(verticalSpacer, 4, 2, 1, 1);


        gridLayout_8->addWidget(frame_4, 0, 0, 1, 1);

        stackedWidget->addWidget(find_pw);
        reg_page = new QWidget();
        reg_page->setObjectName("reg_page");
        gridLayout = new QGridLayout(reg_page);
        gridLayout->setObjectName("gridLayout");
        frame_2 = new QFrame(reg_page);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_5 = new QGridLayout(frame_2);
        gridLayout_5->setObjectName("gridLayout_5");
        reg_log = new QTextEdit(frame_2);
        reg_log->setObjectName("reg_log");
        reg_log->setMaximumSize(QSize(16777215, 300));
        reg_log->setStyleSheet(QString::fromUtf8("border:none;"));
        reg_log->setReadOnly(true);

        gridLayout_5->addWidget(reg_log, 0, 1, 1, 4);

        reg_nalb = new QLabel(frame_2);
        reg_nalb->setObjectName("reg_nalb");

        gridLayout_5->addWidget(reg_nalb, 1, 1, 1, 1);

        reg_name = new QLineEdit(frame_2);
        reg_name->setObjectName("reg_name");

        gridLayout_5->addWidget(reg_name, 1, 2, 1, 2);

        horizontalSpacer_7 = new QSpacerItem(191, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_7, 2, 0, 1, 1);

        reg_pnlb = new QLabel(frame_2);
        reg_pnlb->setObjectName("reg_pnlb");

        gridLayout_5->addWidget(reg_pnlb, 2, 1, 1, 1);

        reg_pn = new QLineEdit(frame_2);
        reg_pn->setObjectName("reg_pn");

        gridLayout_5->addWidget(reg_pn, 2, 2, 1, 2);

        pn_ckbtn = new QPushButton(frame_2);
        pn_ckbtn->setObjectName("pn_ckbtn");

        gridLayout_5->addWidget(pn_ckbtn, 2, 4, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(191, 27, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_8, 2, 5, 1, 1);

        reg_idlb = new QLabel(frame_2);
        reg_idlb->setObjectName("reg_idlb");

        gridLayout_5->addWidget(reg_idlb, 3, 1, 1, 1);

        reg_id = new QLineEdit(frame_2);
        reg_id->setObjectName("reg_id");

        gridLayout_5->addWidget(reg_id, 3, 2, 1, 2);

        id_ckbtn = new QPushButton(frame_2);
        id_ckbtn->setObjectName("id_ckbtn");

        gridLayout_5->addWidget(id_ckbtn, 3, 4, 1, 1);

        reg_pwlb = new QLabel(frame_2);
        reg_pwlb->setObjectName("reg_pwlb");

        gridLayout_5->addWidget(reg_pwlb, 4, 1, 1, 1);

        reg_pw = new QLineEdit(frame_2);
        reg_pw->setObjectName("reg_pw");

        gridLayout_5->addWidget(reg_pw, 4, 2, 1, 2);

        reg_btn = new QPushButton(frame_2);
        reg_btn->setObjectName("reg_btn");

        gridLayout_5->addWidget(reg_btn, 5, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 62, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_5->addItem(verticalSpacer_4, 6, 3, 1, 1);


        gridLayout->addWidget(frame_2, 0, 0, 1, 1);

        stackedWidget->addWidget(reg_page);
        main_page = new QWidget();
        main_page->setObjectName("main_page");
        gridLayout_10 = new QGridLayout(main_page);
        gridLayout_10->setObjectName("gridLayout_10");
        frame_5 = new QFrame(main_page);
        frame_5->setObjectName("frame_5");
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_12 = new QGridLayout(frame_5);
        gridLayout_12->setObjectName("gridLayout_12");
        reg_log_2 = new QTextEdit(frame_5);
        reg_log_2->setObjectName("reg_log_2");
        reg_log_2->setMaximumSize(QSize(16777215, 40));
        reg_log_2->setStyleSheet(QString::fromUtf8("border:none;"));
        reg_log_2->setReadOnly(true);

        gridLayout_12->addWidget(reg_log_2, 0, 0, 1, 1);

        tabWidget = new QTabWidget(frame_5);
        tabWidget->setObjectName("tabWidget");
        all_tab = new QWidget();
        all_tab->setObjectName("all_tab");
        gridLayout_11 = new QGridLayout(all_tab);
        gridLayout_11->setObjectName("gridLayout_11");
        tableView = new QTableView(all_tab);
        tableView->setObjectName("tableView");

        gridLayout_11->addWidget(tableView, 0, 0, 1, 1);

        tabWidget->addTab(all_tab, QString());
        author_tab = new QWidget();
        author_tab->setObjectName("author_tab");
        listView = new QListView(author_tab);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(270, 120, 256, 192));
        tabWidget->addTab(author_tab, QString());

        gridLayout_12->addWidget(tabWidget, 1, 0, 1, 1);


        gridLayout_10->addWidget(frame_5, 0, 0, 1, 1);

        stackedWidget->addWidget(main_page);
        find_id = new QWidget();
        find_id->setObjectName("find_id");
        gridLayout_7 = new QGridLayout(find_id);
        gridLayout_7->setObjectName("gridLayout_7");
        frame_3 = new QFrame(find_id);
        frame_3->setObjectName("frame_3");
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_6 = new QGridLayout(frame_3);
        gridLayout_6->setObjectName("gridLayout_6");
        find_log = new QTextEdit(frame_3);
        find_log->setObjectName("find_log");
        find_log->setMaximumSize(QSize(16777215, 300));
        find_log->setStyleSheet(QString::fromUtf8("border: none;\n"
""));
        find_log->setReadOnly(true);

        gridLayout_6->addWidget(find_log, 0, 1, 1, 3);

        horizontalSpacer_5 = new QSpacerItem(207, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        f_nmlb = new QLabel(frame_3);
        f_nmlb->setObjectName("f_nmlb");

        gridLayout_6->addWidget(f_nmlb, 1, 1, 1, 1);

        f_inname = new QLineEdit(frame_3);
        f_inname->setObjectName("f_inname");

        gridLayout_6->addWidget(f_inname, 1, 2, 1, 2);

        horizontalSpacer_6 = new QSpacerItem(207, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_6, 1, 4, 1, 1);

        f_pnlb = new QLabel(frame_3);
        f_pnlb->setObjectName("f_pnlb");

        gridLayout_6->addWidget(f_pnlb, 2, 1, 1, 1);

        f_inpn = new QLineEdit(frame_3);
        f_inpn->setObjectName("f_inpn");

        gridLayout_6->addWidget(f_inpn, 2, 2, 1, 2);

        verticalSpacer_3 = new QSpacerItem(20, 140, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_6->addItem(verticalSpacer_3, 4, 3, 1, 1);

        f_btn = new QPushButton(frame_3);
        f_btn->setObjectName("f_btn");

        gridLayout_6->addWidget(f_btn, 3, 1, 1, 3);


        gridLayout_7->addWidget(frame_3, 0, 0, 1, 1);

        stackedWidget->addWidget(find_id);

        gridLayout_2->addWidget(stackedWidget, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 744, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Ubuntu Sans'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt; font-weight:700;\">\353\257\274\355\230\270\354\235\230 \354\204\234\354\236\254</span></p></body></html>", nullptr));
        reg_gobtn->setText(QCoreApplication::translate("MainWindow", "\355\232\214\354\233\220\352\260\200\354\236\205", nullptr));
        loginbtn->setText(QCoreApplication::translate("MainWindow", "\353\241\234\352\267\270\354\235\270", nullptr));
        id_label->setText(QCoreApplication::translate("MainWindow", "\354\225\204\354\235\264\353\224\224", nullptr));
        pw_label->setText(QCoreApplication::translate("MainWindow", "\353\271\204\353\260\200\353\262\210\355\230\270", nullptr));
        f_idbtn->setText(QCoreApplication::translate("MainWindow", "\354\225\204\354\235\264\353\224\224 \354\260\276\352\270\260", nullptr));
        f_pwbtn->setText(QCoreApplication::translate("MainWindow", "\353\271\204\353\260\200\353\262\210\355\230\270 \354\260\276\352\270\260", nullptr));
        login_log->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Ubuntu Sans'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:20pt;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20p"
                        "t;\">\353\241\234\352\267\270\354\235\270</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:20pt;\"><br /></p></body></html>", nullptr));
        lbl->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        find_log_2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Ubuntu Sans'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:20pt;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style"
                        "=\" font-size:20pt;\">\353\271\204\353\260\200\353\262\210\355\230\270 \354\260\276\352\270\260</span></p></body></html>", nullptr));
        fp_idlb->setText(QCoreApplication::translate("MainWindow", "\354\225\204\354\235\264\353\224\224", nullptr));
        fp_pnlb->setText(QCoreApplication::translate("MainWindow", "\354\240\204\355\231\224\353\262\210\355\230\270", nullptr));
        fp_btn->setText(QCoreApplication::translate("MainWindow", "\353\271\204\353\260\200\353\262\210\355\230\270 \354\260\276\352\270\260", nullptr));
        reg_log->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Ubuntu Sans'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:20pt;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style"
                        "=\" font-size:20pt;\">\355\232\214\354\233\220\352\260\200\354\236\205</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:20pt;\"><br /></p></body></html>", nullptr));
        reg_nalb->setText(QCoreApplication::translate("MainWindow", "\354\235\264\353\246\204", nullptr));
        reg_pnlb->setText(QCoreApplication::translate("MainWindow", "\354\240\204\355\231\224\353\262\210\355\230\270", nullptr));
        pn_ckbtn->setText(QCoreApplication::translate("MainWindow", "\354\244\221\353\263\265\355\231\225\354\235\270", nullptr));
        reg_idlb->setText(QCoreApplication::translate("MainWindow", "\354\225\204\354\235\264\353\224\224", nullptr));
        id_ckbtn->setText(QCoreApplication::translate("MainWindow", "\354\244\221\353\263\265\355\231\225\354\235\270", nullptr));
        reg_pwlb->setText(QCoreApplication::translate("MainWindow", "\353\271\204\353\260\200\353\262\210\355\230\270", nullptr));
        reg_btn->setText(QCoreApplication::translate("MainWindow", "\355\232\214\354\233\220\352\260\200\354\236\205", nullptr));
        reg_log_2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Ubuntu Sans'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\353\251\224\354\235\270\355\231\224\353\251\264</p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(all_tab), QCoreApplication::translate("MainWindow", "\354\240\204\354\262\264", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(author_tab), QCoreApplication::translate("MainWindow", "\354\236\221\352\260\200", nullptr));
        find_log->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Ubuntu Sans'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:20pt;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style"
                        "=\" font-size:20pt;\">\354\225\204\354\235\264\353\224\224 \354\260\276\352\270\260</span></p></body></html>", nullptr));
        f_nmlb->setText(QCoreApplication::translate("MainWindow", "\354\235\264\353\246\204", nullptr));
        f_pnlb->setText(QCoreApplication::translate("MainWindow", "\354\240\204\355\231\224\353\262\210\355\230\270", nullptr));
        f_btn->setText(QCoreApplication::translate("MainWindow", "\354\225\204\354\235\264\353\224\224 \354\260\276\352\270\260", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
