#include "PowerMainWindow.h"
#include <QtWidgets>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PowerMainWindow w;
    w.show();
    return a.exec();
}
