#include "PowerMainWindow.h"
#include "ui_PowerMainWindow.h"
#include <QPalette>

PowerMainWindow::PowerMainWindow(QWidget *Pparent)
    : QMainWindow(Pparent)
    , ui(new Ui::PowerMainWindow)
{
    ui->setupUi(this);

}

PowerMainWindow::~PowerMainWindow()
{
    delete ui;
}


void PowerMainWindow::on_spinBox_valueChanged(int arg1)
{
    on_Battery_valueChanged(arg1);
}


void PowerMainWindow::on_Battery_valueChanged(int value)
{
    ui->Battery->setValue(value);

    //int i = 0;

    /*

    int previousValue;

    if(previousValue != value)
        previousValue = value;
    */
    powerpopup lowpop;

    QString danger = "QProgressBar { border: 1px solid black;border-radius: 7px;}";
    danger+= "QProgressBar::chunk { background-color: red; width: 5px;}";
    QString safe = "QProgressBar { border: 1px solid black;border-radius: 7px;}";
    safe+= "QProgressBar::chunk { background-color: green; width: 5px;}";

    if(ui->Battery->value()<21){
        ui->Battery->setStyleSheet(danger);
        if(ui->Battery->value() == 20){
            lowpop.setModal(true);
            lowpop.exec();
        }
    }
    else
        ui->Battery->setStyleSheet(safe);
}

