#ifndef POPUP_H
#define POPUP_H

#include <QObject>
#include <QWidget>
#include <QDialog>

namespace Ui {
class popup;
}


class popup : public QDialog
{
    Q_OBJECT

public:
    explicit popup(QWidget *Eparent = nullptr);
    ~popup();

private slots:


    void on_ConfimationButton_accepted();

    void on_ConfimationButton_rejected();

private:
    Ui::popup *ui;
};

#endif // POPUP_H
