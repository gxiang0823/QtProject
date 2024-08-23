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
        rectangle(srcImage,rect,Scalar(255,0,0));
    }

    if(srcImage.data == nullptr) return;
    // 把opencv里面的Mat格式数据(BGR)转Qt里面的QImage(RGB)
    cvtColor(srcImage,srcImage,COLOR_BGR2RGB);
    QImage image(srcImage.data,srcImage.cols,srcImage.rows,srcImage.step1(),QImage::Format_RGB888);
    QPixmap mmp = QPixmap::fromImage(image);
    ui->videoLb->setPixmap(mmp);
}
