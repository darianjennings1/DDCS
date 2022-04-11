#ifndef PLOTMAINWINDOW_H
#define PLOTMAINWINDOW_H

#include "qcustomplot.h"
#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class PlotMainWindow; }
QT_END_NAMESPACE

class PlotMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    PlotMainWindow(QWidget *parent = nullptr);
    ~PlotMainWindow();

    void setupScatterPixmapDemo(QCustomPlot *customPlot);

private slots:
   // void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::PlotMainWindow *ui;
    QString demoName;
};
#endif // PLOTMAINWINDOW_H
