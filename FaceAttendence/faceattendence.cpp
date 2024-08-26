#include "faceattendence.h"
#include "ui_faceattendence.h"

FaceAttendence::FaceAttendence(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FaceAttendence)
{
    ui->setupUi(this);
    // 打开摄像头
    cap.open(0);//dev/video
    //启动定时器事件
    startTimer(100);

    // 导入级联分类器文件
    cascade.load("D:/Learning/opencv452/etc/haarcascades/haarcascade_frontalface_alt2.xml");

    //QTcpSocket当断开连接的时候dsiconnect信号，连接成功会发送connected
    connect(&msocket,&QTcpSocket::disconnected, this, &FaceAttendence::start_connect);
    connect(&msocket,&QTcpSocket::connected, this, &FaceAttendence::stop_connect);


    //定时器连接服务器
    connect(&mtimer, &QTimer::timeout,this,&FaceAttendence::timer_connect);
    //启动定时器
    mtimer.start(5000);//每5s连接一次，直到连接成功就不在连接
}

FaceAttendence::~FaceAttendence()
{
    delete ui;
}

void FaceAttendence::timerEvent(QTimerEvent *e)
{
    // 采集数据
    Mat srcImage;
    if(cap.grab())
    {
        cap.read(srcImage);// 读取一帧数据
    }

    Mat grayImage;
    //转灰度图
    cvtColor(srcImage,grayImage,COLOR_BGR2GRAY);
    // 检测人脸数据
    std::vector<Rect> faceRects;
    cascade.detectMultiScale(grayImage,faceRects);
    if(faceRects.size()>0)
    {
        Rect rect = faceRects.at(0); // 第一个人脸的矩形框
        // rectangle(srcImage,rect,Scalar(255,0,0));

        // 移动人脸框(图片 -- QLabel)
        ui->headpicLb->move(rect.x, rect.y);

        //把Mat数据转化为QbyteArray -->编码成jpg格式
        std::vector<uchar> buf;
        cv::imencode(".jpg",srcImage,buf);
        QByteArray byte((const char*)buf.data(),buf.size());
        //准备发送
        quint64 backsize = byte.size();
        QByteArray sendData;
        QDataStream stream(&sendData,QIODevice::WriteOnly);
        stream.setVersion(QDataStream::Qt_6_2);
        stream<<backsize<<byte;
        //发送
        msocket.write(sendData);

    }
    else
    {
        //把人脸框移动到中心位置
        ui->headpicLb->move(120,60);
    }

    if(srcImage.data == nullptr) return;
    // 把opencv里面的Mat格式数据(BGR)转Qt里面的QImage(RGB)
    cvtColor(srcImage,srcImage,COLOR_BGR2RGB);
    QImage image(srcImage.data,srcImage.cols,srcImage.rows,srcImage.step1(),QImage::Format_RGB888);
    QPixmap mmp = QPixmap::fromImage(image);
    ui->videoLb->setPixmap(mmp);
}

void FaceAttendence::timer_connect()
{
    //连接服务器
    msocket.connectToHost("10.26.142.242",9999);
    qDebug()<<"正在连接服务器";
}

void FaceAttendence::stop_connect()
{
    mtimer.stop();
    qDebug()<<"成功连接服务器";
}

void FaceAttendence::start_connect()
{
    mtimer.start(5000);//启动定时器
    qDebug()<<"断开连接";
}
