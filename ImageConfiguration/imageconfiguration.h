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
#include <QTextBrowser>


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

private slots:
    void captureImage();
    void onImageCaptured(int id, QImage preview);

private:
    Ui::ImageConfiguration *ui;

    QCamera *camera;
    QVideoWidget *finder;
    QImageCapture *imageCapture;
    QTextBrowser *textBrowser;
    QPushButton *captureButton;
    QLabel *imageLabel;


};
#endif // IMAGECONFIGURATION_H
