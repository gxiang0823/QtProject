#include "imageconfiguration.h"
#include "ui_imageconfiguration.h"
#include <QCamera>
#include <QCameraDevice>


ImageConfiguration::ImageConfiguration(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ImageConfiguration)
{
    ui->setupUi(this);

    QCamera camera;
    QCameraViewfinder finder;

}

ImageConfiguration::~ImageConfiguration()
{
    delete ui;
}
