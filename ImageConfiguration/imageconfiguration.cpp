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

<<<<<<< HEAD
    finder = new QVideoWidget();
    finder->show();
    captureSession.setVideoOutput(finder);
=======
    QPushButton *captureButton = new QPushButton("Capture",this);
>>>>>>> bcdd4aaf981325be71b51c15df47ad0bec840326

    imageCapture = new QImageCapture;
    captureSession.setImageCapture(imageCapture);

    camera->start();
    //on shutter button pressed


<<<<<<< HEAD
=======
    // 界面布局设置
    QVBoxLayout *vboxl = new QVBoxLayout;
    vboxl->addWidget(ui->label);
    vboxl->addWidget(ui->captureButton);
>>>>>>> bcdd4aaf981325be71b51c15df47ad0bec840326

}

ImageConfiguration::~ImageConfiguration()
{
    delete ui;
}

void ImageConfiguration::captureImage()
{
    imageCapture->capture();
}

