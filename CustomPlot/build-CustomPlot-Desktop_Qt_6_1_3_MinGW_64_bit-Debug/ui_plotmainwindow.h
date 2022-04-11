/********************************************************************************
** Form generated from reading UI file 'plotmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTMAINWINDOW_H
#define UI_PLOTMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_PlotMainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QCustomPlot *customPlot;
    QComboBox *comboBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PlotMainWindow)
    {
        if (PlotMainWindow->objectName().isEmpty())
            PlotMainWindow->setObjectName(QString::fromUtf8("PlotMainWindow"));
        PlotMainWindow->resize(551, 420);
        centralwidget = new QWidget(PlotMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        customPlot = new QCustomPlot(centralwidget);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        comboBox = new QComboBox(customPlot);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(20, 10, 61, 21));
        comboBox->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(customPlot);

        PlotMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PlotMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 551, 21));
        PlotMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(PlotMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PlotMainWindow->setStatusBar(statusbar);

        retranslateUi(PlotMainWindow);

        QMetaObject::connectSlotsByName(PlotMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PlotMainWindow)
    {
        PlotMainWindow->setWindowTitle(QCoreApplication::translate("PlotMainWindow", "TestMainWindow", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("PlotMainWindow", "Pitch", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("PlotMainWindow", "Yaw", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("PlotMainWindow", "Roll", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("PlotMainWindow", "Throttle", nullptr));

        comboBox->setCurrentText(QCoreApplication::translate("PlotMainWindow", "Pitch", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlotMainWindow: public Ui_PlotMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTMAINWINDOW_H
