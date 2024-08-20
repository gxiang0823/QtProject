#ifndef IMAGECONFIGURATION_H
#define IMAGECONFIGURATION_H

#include <QWidget>
#include <QCamera>
#include <QVideoWidget>
#include <QMediaCaptureSession>
#include <QImageCapture>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMediaPlayer>
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui {
class ImageConfiguration;
}
QT_END_NAMESPACE

class ImageConfiguration : public QWidget
{
    Q_OBJECT

public slots:
    void captureImage();

public:
    ImageConfiguration(QWidget *parent = nullptr);
    ~ImageConfiguration();

private:
    Ui::ImageConfiguration *ui;
    QCamera *camera;
    QMediaCaptureSession *captureSession;
    QImageCapture *imageCapture;


};
#endif // IMAGECONFIGURATION_H
