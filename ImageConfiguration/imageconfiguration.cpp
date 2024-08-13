#include "imageconfiguration.h"
#include "ui_imageconfiguration.h"
#include <QCamera>
#include <QVideoWidget>


ImageConfiguration::ImageConfiguration(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ImageConfiguration)
{
    ui->setupUi(this);

    QCamera camera;
    QVideoWidget finder;

}

ImageConfiguration::~ImageConfiguration()
{
    delete ui;
}
