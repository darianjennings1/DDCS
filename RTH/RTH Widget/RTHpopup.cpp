#include "RTHpopup.h"
#include "ui_RTHpopup.h"

RTHpopup::RTHpopup(QWidget *Rparent) :
      QDialog(Rparent),
      ui(new Ui::RTHpopup)
{
    ui->setupUi(this);
}

RTHpopup::~RTHpopup()
{
   delete ui;
}


void RTHpopup::on_ConfimationButton_accepted()
{
    //enable emergency protocol
}


void RTHpopup::on_ConfimationButton_rejected()
{
    this->close();
}

