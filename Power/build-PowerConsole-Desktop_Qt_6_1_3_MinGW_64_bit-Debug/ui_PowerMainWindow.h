/********************************************************************************
** Form generated from reading UI file 'PowerMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POWERMAINWINDOW_H
#define UI_POWERMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PowerMainWindow
{
public:
    QWidget *centralwidget;
    QProgressBar *Battery;
    QSpinBox *spinBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PowerMainWindow)
    {
        if (PowerMainWindow->objectName().isEmpty())
            PowerMainWindow->setObjectName(QString::fromUtf8("PowerMainWindow"));
        PowerMainWindow->resize(800, 600);
        centralwidget = new QWidget(PowerMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Battery = new QProgressBar(centralwidget);
        Battery->setObjectName(QString::fromUtf8("Battery"));
        Battery->setEnabled(true);
        Battery->setGeometry(QRect(60, 100, 118, 23));
        QPalette palette;
        QBrush brush(QColor(255, 170, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette.setBrush(QPalette::Active, QPalette::Link, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Link, brush);
        QBrush brush1(QColor(0, 120, 215, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Link, brush);
        Battery->setPalette(palette);
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        Battery->setFont(font);
        Battery->setValue(0);
        Battery->setAlignment(Qt::AlignCenter);
        Battery->setTextVisible(true);
        Battery->setInvertedAppearance(false);
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(320, 180, 42, 22));
        PowerMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PowerMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        PowerMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(PowerMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PowerMainWindow->setStatusBar(statusbar);

        retranslateUi(PowerMainWindow);

        QMetaObject::connectSlotsByName(PowerMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PowerMainWindow)
    {
        PowerMainWindow->setWindowTitle(QCoreApplication::translate("PowerMainWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PowerMainWindow: public Ui_PowerMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POWERMAINWINDOW_H
