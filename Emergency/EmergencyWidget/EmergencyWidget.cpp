#include "EmergencyWidget.h"
#include "ui_EmergencyWidget.h"
#include <QPalette>

EmergencyMainWindow::EmergencyMainWindow(QWidget *Eparent)
    : QMainWindow(Eparent)
    , ui(new Ui::EmergencyMainWindow)
{
    ui->setupUi(this);
}

EmergencyMainWindow::~EmergencyMainWindow()
{
    delete ui;
}


void EmergencyMainWindow::on_pb_emergency_pressed()
{

    ui->pb_emergency->setStyleSheet(" background-color: darkRed;"
                               "border-style: solid;"
                               "border-width:2px;"
                               "border-radius:50px;"
                               "border-color: black;"
                               "max-width:100px;"
                               "max-height:100px;"
                               "min-width:100px;"
                               "min-height:100px; ");

}


void EmergencyMainWindow::on_pb_emergency_released()
{
    ui->pb_emergency->setStyleSheet(" background-color: red;"
                               "border-style: solid;"
                               "border-width:2px;"
                               "border-radius:50px;"
                               "border-color: black;"
                               "max-width:100px;"
                               "max-height:100px;"
                               "min-width:100px;"
                               "min-height:100px; ");
}


void EmergencyMainWindow::on_pb_emergency_clicked()
{
    popup widpopup;
    widpopup.setModal(true);
    widpopup.exec();

}

