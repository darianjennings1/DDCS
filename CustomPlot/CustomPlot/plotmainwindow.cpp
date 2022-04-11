#include "plotmainwindow.h"
#include "ui_plotmainwindow.h"
#include <QScreen>
#include <QDebug>

PlotMainWindow::PlotMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PlotMainWindow)
{
    ui->setupUi(this);
    setGeometry(400, 250, 542, 390);
    setupScatterPixmapDemo(ui->customPlot);
    //setWindowTitle("QCustomPlot: DDCS demo plot");
    statusBar()->clearMessage();
}

void PlotMainWindow::setupScatterPixmapDemo(QCustomPlot *customPlot){

    demoName = "Scatter Pixmap DDCS Demo";
   // customPlot->axisRect()->setBackground(QPixmap("./rattler.jpg"));
    customPlot->addGraph();
    customPlot->graph()->setLineStyle(QCPGraph::lsLine);
    QPen pen;
    pen.setColor(QColor(255, 200, 20, 200));
    pen.setStyle(Qt::DashLine);
    pen.setWidthF(2.5);
    customPlot->graph()->setPen(pen);
    customPlot->graph()->setBrush(QBrush(QColor(255,200,20,70)));
    //customPlot->graph()->setScatterStyle(QCPScatterStyle(QPixmap("./sun.png")));
    // set graph name, will show up in legend next to icon:
    customPlot->graph()->setName("Variable Data\nfor viewing");
    // set data:
    QVector<double> pitchData;
    QVector<double> year, value;
    year  << 2005 << 2006 << 2007 << 2008  << 2009  << 2010; //this will be replaced with values from redis
    value << 2.17 << 3.42 << 4.94 << 10.38 << 15.86 << 29.33;
    pitchData << 12.3 << 6.5 << 23.5 << 7.5 << 34 << 56;


/* THIS IS TO INSERT USING NUMBER OF INDEX*/

    /*
    double i = 2004;
    double j = 6.4;  //random values
    double numOfItems = value.length();

    year.insert(numOfItems, i);
    year.removeFirst() //removes the first index to keep the array a set number of items

    value.insert(numOfItems, j)
    value.removeFirst() //removes the first index to keep the array a set number of items
    */

    customPlot->graph()->setData(year, pitchData);

    // set title of plot:
    customPlot->plotLayout()->insertRow(0);
    customPlot->plotLayout()->addElement(0, 0, new QCPTextElement(customPlot, "Drone Data", QFont("sans", 12, QFont::Bold)));
    // axis configurations:
    customPlot->xAxis->setLabel("Time");
    customPlot->yAxis->setLabel("Pitch");
    customPlot->xAxis2->setVisible(true);
    customPlot->yAxis2->setVisible(true);
    customPlot->xAxis2->setTickLabels(false);
    customPlot->yAxis2->setTickLabels(false);
    customPlot->xAxis2->setTicks(false);
    customPlot->yAxis2->setTicks(false);
    customPlot->xAxis2->setSubTicks(false);
    customPlot->yAxis2->setSubTicks(false);
    customPlot->xAxis->setRange(year.at(0), year.at(5));
    //customPlot->xAxis->setRange(3000, 3010);
    customPlot->yAxis->setRange(0, 52);
    // setup legend:
    customPlot->legend->setFont(QFont(font().family(), 7));
    customPlot->legend->setIconSize(50, 20);
    customPlot->legend->setVisible(true);
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignLeft | Qt::AlignTop);

}

PlotMainWindow::~PlotMainWindow()
{
    delete ui;
}


void PlotMainWindow::on_comboBox_currentIndexChanged(int index)
{

    QVector<double> pitchData; //gathered from redis, random values for now
    QVector<double> yawData;
    QVector<double> rollData;
    QVector<double> throttleData;
    QVector<double> ranTimeData;
    QVector<double> ranTimeTwo;
    pitchData << 12.3 << 6.5 << 23.5 << 7.5 << 34 << 56;
    yawData << 2 << 3 << 4 << 5 << 6 << 8;
    rollData << 20 << 30 << 40 << 50 << 60 << 80;
    throttleData << 32 << 33 << 34 << 35 << 36 << 38;
    ranTimeData << 1 << 2 << 3 << 4 << 5 << 6;
    ranTimeTwo << 7 << 8 <<9 << 10<< 11 << 12;

    if(index ==0){
        ui->customPlot->graph()->setData(ranTimeData, pitchData);
        ui->customPlot->yAxis->setLabel("Pitch");
    }else if (index == 1){
        ui->customPlot->graph()->setData(ranTimeTwo, yawData);
        ui->customPlot->yAxis->setLabel("Yaw");
    }else if(index== 2){
        ui->customPlot->graph()->setData(ranTimeTwo, rollData);
        ui->customPlot->yAxis->setLabel("Roll");
    }else if (index == 3){
        ui->customPlot->graph()->setData(ranTimeTwo, throttleData);
        ui->customPlot->yAxis->setLabel("Throttle");
    }
   ui->customPlot->rescaleAxes();
   ui->customPlot->replot();
}

