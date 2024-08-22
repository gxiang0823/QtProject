#include "imageconfiguration.h"
#include "ui_imageconfiguration.h"

ImageConfiguration::ImageConfiguration(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ImageConfiguration)
{
    ui->setupUi(this);

    // 摄像头设置
    QMediaCaptureSession captureSession;
    camera = new QCamera;
    captureSession.setCamera(camera);

    finder = new QVideoWidget();
    finder->show();
    captureSession.setVideoOutput(finder);

    imageCapture = new QImageCapture;
    captureSession.setImageCapture(imageCapture);

    camera->start();
    //on shutter button pressed



}

ImageConfiguration::~ImageConfiguration()
{
    delete ui;
}

void ImageConfiguration::captureImage()
{
    imageCapture->capture();
}

