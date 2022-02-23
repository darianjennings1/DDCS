#include "RTHWidget.h"
#include "ui_RTHWidget.h"
#include <QPalette>

RTHMainWindow::RTHMainWindow(QWidget *Rparent)
    : QMainWindow(Rparent)
    , ui(new Ui::RTHMainWindow)
{
    ui->setupUi(this);
}

RTHMainWindow::~RTHMainWindow()
{
    delete ui;
}


void RTHMainWindow::on_pb_RTH_pressed()
{

    ui->pb_RTH->setStyleSheet(" background-color: darkBlue;"
                               "border-style: solid;"
                               "border-width:2px;"
                               "border-radius:50px;"
                               "border-color: black;"
                               "max-width:100px;"
                               "max-height:100px;"
                               "min-width:100px;"
                               "min-height:100px; ");

}


void RTHMainWindow::on_pb_RTH_released()
{
    ui->pb_RTH->setStyleSheet(" background-color: blue;"
                               "border-style: solid;"
                               "border-width:2px;"
                               "border-radius:50px;"
                               "border-color: black;"
                               "max-width:100px;"
                               "max-height:100px;"
                               "min-width:100px;"
                               "min-height:100px; ");
}


void RTHMainWindow::on_pb_RTH_clicked()
{
    RTHpopup widpopup;
    widpopup.setModal(true);
    widpopup.exec();

}

