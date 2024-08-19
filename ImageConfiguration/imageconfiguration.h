#ifndef IMAGECONFIGURATION_H
#define IMAGECONFIGURATION_H

#include <QWidget>
#include <QCamera>
#include <QVideoWidget>
#include <QMediaCaptureSession>
#include <QImageCapture>

QT_BEGIN_NAMESPACE
namespace Ui {
class ImageConfiguration;
}
QT_END_NAMESPACE

class ImageConfiguration : public QWidget
{
    Q_OBJECT

public:
    ImageConfiguration(QWidget *parent = nullptr);
    ~ImageConfiguration();

private:
    Ui::ImageConfiguration *ui;

    QCamera *camera;
    QVideoWidget *finder;
    QMediaCaptureSession *session;
    QImageCapture *imageCapture;

};
#endif // IMAGECONFIGURATION_H
