#ifndef POWERPOPUP_H
#define POWERPOPUP_H

#include <QObject>
#include <QWidget>
#include <QDialog>

namespace Ui {
class powerpopup;
}

class powerpopup : public QDialog
{
    Q_OBJECT

public:
    explicit powerpopup(QWidget *Pparent = nullptr);
    ~powerpopup();

private slots:
    void on_pushButton_clicked();

private:
    Ui::powerpopup *ui;
};

#endif // POWERPOPUP_H
