#ifndef IMAGECONFIGURATION_H
#define IMAGECONFIGURATION_H

#include <QWidget>

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
};
#endif // IMAGECONFIGURATION_H
