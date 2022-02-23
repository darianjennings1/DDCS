#include "EmergencyWidget.h"
#include <QtWidgets>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EmergencyMainWindow w;
    w.show();
    return a.exec();
}
