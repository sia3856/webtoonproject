#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QMetaType>
#include <QSet>
#include <QStandardPaths>
#include <QTcpServer>
#include <QTcpSocket>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlRecord>

namespace Ui {
class MainWindow;
}

// [ex.02]
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QSqlDatabase m_db;
    QSqlTableModel *m_model;

    QTcpServer* m_server;
    QSet<QTcpSocket*> qset_connectedSKT;

    void appendToSocketList(QTcpSocket* socket);
    void sendMessage(QTcpSocket* socket);
    void sendAttachment(QTcpSocket* socket, QString filePath);
    void refreshComboBox();
    bool initializeDataBase();

signals:
    void singal_newMessage(QString);

private slots:
    void slot_newConnection();
    void slot_discardSocket();
    void slot_displayError(QAbstractSocket::SocketError socketError);
    void slot_readSocket();
    void on_pushButton_sendMessage_clicked();
    void on_pushButton_sendAttachment_clicked();
    void slot_displayMessage(const QString& str);
    void send_rmsg(QTcpSocket* socket, QString fileType);
    void send_rmsg(QTcpSocket* socket, QString fileType ,QString result);


};

#endif // MAINWINDOW_H
