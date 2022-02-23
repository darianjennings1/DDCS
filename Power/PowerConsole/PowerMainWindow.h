#ifndef POWERMAINWINDOW_H
#define POWERMAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <algorithm>
#include "powerpopup.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PowerMainWindow; }
QT_END_NAMESPACE

class PowerMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    PowerMainWindow(QWidget *Pparent = nullptr);
    ~PowerMainWindow();

private slots:
    //void on_Battery_valueChanged(int value);

    void on_spinBox_valueChanged(int arg1);

    void on_Battery_valueChanged(int value);

private:
    Ui::PowerMainWindow *ui;
};
#endif // POWERMAINWINDOW_H
