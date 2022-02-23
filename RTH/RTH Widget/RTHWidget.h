#ifndef RTHWIDGET_H
#define RTHWIDGET_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <algorithm>
#include "RTHpopup.h"

QT_BEGIN_NAMESPACE
namespace Ui { class RTHMainWindow; }
QT_END_NAMESPACE

class RTHMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    RTHMainWindow(QWidget *Rparent = nullptr);
    ~RTHMainWindow();

private slots:
    void on_pb_RTH_clicked();

    void on_pb_RTH_pressed();

    void on_pb_RTH_released();

private:
    Ui::RTHMainWindow *ui;
};
#endif // RTHWIDGET_H
