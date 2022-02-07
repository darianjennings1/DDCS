#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPalette>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


/*void on_pb_emergency_clicked()
{

    popup widpopup;
    widpopup.setModal(true);
    widpopup.exec();

}
*/


void MainWindow::on_pb_emergency_pressed()
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


void MainWindow::on_pb_emergency_released()
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


void MainWindow::on_pb_emergency_clicked()
{
    popup widpopup;
    widpopup.setModal(true);
    widpopup.exec();

}

