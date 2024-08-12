#include "imageconfiguration.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageConfiguration w;
    w.show();
    return a.exec();
}
