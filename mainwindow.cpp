#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
   ui->graphicsEADI->setPitch(arg1);
   ui->graphicsEADI->redraw();
}


void MainWindow::on_doubleSpinBox_2_valueChanged(double arg1)
{
    ui->graphicsEADI->setRoll(arg1);
    ui->graphicsEADI->redraw();
}

