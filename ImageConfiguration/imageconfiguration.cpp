#include "imageconfiguration.h"
#include "ui_imageconfiguration.h"

ImageConfiguration::ImageConfiguration(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ImageConfiguration)
{
    ui->setupUi(this);

    // 摄像头设置
    session = new QMediaCaptureSession();
    camera = new QCamera;
    session->setCamera(camera);
    finder = new QVideoWidget();
    finder->show();
    session->setVideoOutput(finder);
    imageCapture = new QImageCapture();
    session->setImageCapture(imageCapture);

    camera->start();
    imageCapture->capture();

    // 界面布局
    QVBoxLayout *vboxl = new QVBoxLayout;
    vboxl->addWidget(ui->label);
    vboxl->addWidget(ui->pushButton);

    QVBoxLayout *vboxr = new QVBoxLayout;
    vboxr->addWidget(finder);
    vboxr->addWidget(ui->textBrowser);

    QHBoxLayout *hbox = new QHBoxLayout(this);
    hbox->addLayout(vboxl);
    hbox->addLayout(vboxr);
    this->setLayout(hbox);


}

ImageConfiguration::~ImageConfiguration()
{
    delete ui;
}
