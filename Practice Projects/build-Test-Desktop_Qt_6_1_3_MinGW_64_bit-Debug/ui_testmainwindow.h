/********************************************************************************
** Form generated from reading UI file 'testmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTMAINWINDOW_H
#define UI_TESTMAINWINDOW_H

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

class Ui_TestMainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QCustomPlot *customPlot;
    QComboBox *comboBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TestMainWindow)
    {
        if (TestMainWindow->objectName().isEmpty())
            TestMainWindow->setObjectName(QString::fromUtf8("TestMainWindow"));
        TestMainWindow->resize(551, 420);
        centralwidget = new QWidget(TestMainWindow);
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

        TestMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TestMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 551, 21));
        TestMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(TestMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TestMainWindow->setStatusBar(statusbar);

        retranslateUi(TestMainWindow);

        QMetaObject::connectSlotsByName(TestMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TestMainWindow)
    {
        TestMainWindow->setWindowTitle(QCoreApplication::translate("TestMainWindow", "TestMainWindow", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("TestMainWindow", "Pitch", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("TestMainWindow", "Yaw", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("TestMainWindow", "Roll", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("TestMainWindow", "Throttle", nullptr));

        comboBox->setCurrentText(QCoreApplication::translate("TestMainWindow", "Pitch", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestMainWindow: public Ui_TestMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTMAINWINDOW_H
