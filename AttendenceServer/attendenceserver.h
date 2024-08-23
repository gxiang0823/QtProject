#ifndef ATTENDENCESERVER_H
#define ATTENDENCESERVER_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>


QT_BEGIN_NAMESPACE
namespace Ui {
class AttendenceServer;
}
QT_END_NAMESPACE

class AttendenceServer : public QMainWindow
{
    Q_OBJECT

public:
    AttendenceServer(QWidget *parent = nullptr);
    ~AttendenceServer();

protected slots:
    void accept_client();
    void read_data();
private:
    Ui::AttendenceServer *ui;
    QTcpServer mserver;
    QTcpSocket *msocket;
};
#endif // ATTENDENCESERVER_H
