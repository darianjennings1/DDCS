#ifndef EMERGENCYWIDGET_H
#define EMERGENCYWIDGET_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <algorithm>
#include "popup.h"

QT_BEGIN_NAMESPACE
namespace Ui { class EmergencyMainWindow; }
QT_END_NAMESPACE

class EmergencyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    EmergencyMainWindow(QWidget *Eparent = nullptr);
    ~EmergencyMainWindow();

private slots:
    void on_pb_emergency_clicked();

    void on_pb_emergency_pressed();

    void on_pb_emergency_released();

private:
    Ui::EmergencyMainWindow *ui;
};
#endif // EMERGENCYWIDGET_H
