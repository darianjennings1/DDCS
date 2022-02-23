#include "popup.h"
#include "ui_popup.h"

popup::popup(QWidget *Eparent) :
      QDialog(Eparent),
      ui(new Ui::popup)
{
    ui->setupUi(this);
}

popup::~popup()
{
   delete ui;
}


void popup::on_ConfimationButton_accepted()
{
    //enable emergency protocol
}


void popup::on_ConfimationButton_rejected()
{
    this->close();
}

