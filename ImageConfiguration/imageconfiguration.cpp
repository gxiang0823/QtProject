#include "imageconfiguration.h"
#include "ui_imageconfiguration.h"

ImageConfiguration::ImageConfiguration(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ImageConfiguration)
{
    ui->setupUi(this);

    session = new QMediaCaptureSession();
    camera = new QCamera;
    session->setCamera(camera);
    finder = new QVideoWidget();
    finder->show();
    session->setVideoOutput(finder);
    imageCapture = new QImageCapture();
    session->setImageCapture(imageCapture);

    camera->start();
    //on shutter button pressed
    imageCapture->capture();


}

ImageConfiguration::~ImageConfiguration()
{
    delete ui;
}
