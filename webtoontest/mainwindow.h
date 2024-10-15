#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractSocket>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QHostAddress>
#include <QMessageBox>
#include <QMetaType>
#include <QString>
#include <QStandardPaths>
#include <QTcpSocket>
#include <QImage> //QImage를 사용하기 위한 라이브러리
#include <QPixmap>//QPixmap를 사용하기 위한 라이브러리
#include <QLabel>//QLabel를 사용하기 위한 라이브러리
#include <QMessageBox>//QMessageBox를 사용하기 위한 라이브러리
#include <QScrollArea>
#include <QStandardItemModel>
#include <QTableView>
#include <QRegularExpression>


namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QTcpSocket* m_socket;
    QString fileType;

signals:
    void signal_newMessage(QString);

private slots:
    void slot_discardSocket();
    void slot_displayError(QAbstractSocket::SocketError socketError);
    void slot_readSocket();
    void on_pushButton_clicked();

    void on_f_idbtn_clicked();

    void on_f_pwbtn_clicked();

    void on_reg_gobtn_clicked();
    void on_loginbtn_clicked();
    void on_tabWidget_tabBarClicked(int index);
    void slot_displayMessage(const QString& str);
    void onTableCellClicked(const QModelIndex &index);

};
#endif // MAINWINDOW_H
