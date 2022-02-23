#include "powerpopup.h"
#include "ui_powerpopup.h"

powerpopup::powerpopup(QWidget *Pparent) :
      QDialog(Pparent),
      ui(new Ui::powerpopup)
{
    ui->setupUi(this);
}

powerpopup::~powerpopup()
{
   delete ui;
}


void powerpopup::on_pushButton_clicked()
{
    this->close();
}

