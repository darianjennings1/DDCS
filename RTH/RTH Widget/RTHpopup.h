#ifndef RTHPOPUP_H
#define RTHPOPUP_H

#include <QObject>
#include <QWidget>
#include <QDialog>

namespace Ui {
class RTHpopup;
}

class RTHpopup : public QDialog
{
    Q_OBJECT

public:
    explicit RTHpopup(QWidget *Rparent = nullptr);
    ~RTHpopup();

private slots:

    void on_ConfimationButton_accepted();

    void on_ConfimationButton_rejected();

private:
    Ui::RTHpopup *ui;
};

#endif // RTHPOPUP_H
