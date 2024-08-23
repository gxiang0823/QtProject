#include "attendenceserver.h"
#include "ui_attendenceserver.h"

AttendenceServer::AttendenceServer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AttendenceServer)
{
    ui->setupUi(this);
    // QTcpServer当有客户端连接会发送newConnection
    connect(&mserver, &QTcpServer::newConnection,this,&AttendenceServer::accept_client);
    mserver.listen(QHostAddress::Any,9999);

}

AttendenceServer::~AttendenceServer()
{
    delete ui;
}

//接受客户端连接
void AttendenceServer::accept_client()
{
    // 获取与客户端通信的套接字
    msocket = mserver.nextPendingConnection();

    // 当客户端有数据到达，会发送readyRead信号
    connect(msocket, &QTcpSocket::readyRead,this,&AttendenceServer::read_data);
}

//读取客户端发送的数据
void AttendenceServer::read_data()
{
    // 读取所有的数据
    QString msg = msocket->readAll();
    qDebug()<<msg;
}
