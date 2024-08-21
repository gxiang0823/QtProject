#include "imageconfiguration.h"
#include "ui_imageconfiguration.h"

ImageConfiguration::ImageConfiguration(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ImageConfiguration)
{
    ui->setupUi(this);

    // 摄像头设置
    QVideoWidget *finder = new QVideoWidget(this);

    QPushButton *captureButton = new QPushButton("Capture",this);

    camera = new QCamera(this);

    captureSession = new QMediaCaptureSession(this);
    captureSession->setCamera(camera);

    imageCapture = new QImageCapture(this);
    captureSession->setImageCapture(imageCapture);
    captureSession->setVideoOutput(finder);
    camera->start();

    connect(captureButton, &QPushButton::clicked,this,&ImageConfiguration::captureImage);


    // 界面布局设置
    QVBoxLayout *vboxl = new QVBoxLayout;
    vboxl->addWidget(ui->label);
    vboxl->addWidget(ui->captureButton);

    QVBoxLayout *vboxr = new QVBoxLayout;
    vboxr->addWidget(finder);
    vboxr->addWidget(ui->textBrowser);

    QHBoxLayout *hbox = new QHBoxLayout(this);
    hbox->addLayout(vboxl);
    hbox->addLayout(vboxr);
    this->setLayout(hbox);
}

void ImageConfiguration::captureImage()
{
    int id = imageCapture->captureToFile("/capture_image.jpg");
    if (id == -1)
    {
        QMessageBox::warning(this, "Capture Error", "Failed to capture image.");
    }
}

ImageConfiguration::~ImageConfiguration()
{
    delete ui;
}
