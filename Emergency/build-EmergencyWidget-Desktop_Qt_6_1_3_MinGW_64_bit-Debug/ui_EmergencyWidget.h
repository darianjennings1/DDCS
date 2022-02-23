/********************************************************************************
** Form generated from reading UI file 'EmergencyWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMERGENCYWIDGET_H
#define UI_EMERGENCYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmergencyMainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pb_emergency;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *EmergencyMainWindow)
    {
        if (EmergencyMainWindow->objectName().isEmpty())
            EmergencyMainWindow->setObjectName(QString::fromUtf8("EmergencyMainWindow"));
        EmergencyMainWindow->resize(800, 600);
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        EmergencyMainWindow->setPalette(palette);
        centralwidget = new QWidget(EmergencyMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(120, 60, 201, 171));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pb_emergency = new QPushButton(widget);
        pb_emergency->setObjectName(QString::fromUtf8("pb_emergency"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pb_emergency->sizePolicy().hasHeightForWidth());
        pb_emergency->setSizePolicy(sizePolicy);
        pb_emergency->setMinimumSize(QSize(104, 104));
        pb_emergency->setMaximumSize(QSize(104, 104));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        pb_emergency->setPalette(palette1);
        QFont font;
        font.setBold(false);
        pb_emergency->setFont(font);
        pb_emergency->setAutoFillBackground(false);
        pb_emergency->setStyleSheet(QString::fromUtf8(" background-color: red;\n"
" border-style: solid;\n"
" border-width:2px;\n"
" border-radius:50px;\n"
" border-color: black;\n"
" max-width:100px;\n"
" max-height:100px;\n"
" min-width:100px;\n"
" min-height:100px;"));
        pb_emergency->setIconSize(QSize(18, 18));
        pb_emergency->setFlat(true);

        horizontalLayout->addWidget(pb_emergency);

        EmergencyMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(EmergencyMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        EmergencyMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(EmergencyMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        EmergencyMainWindow->setStatusBar(statusbar);

        retranslateUi(EmergencyMainWindow);

        QMetaObject::connectSlotsByName(EmergencyMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *EmergencyMainWindow)
    {
        EmergencyMainWindow->setWindowTitle(QCoreApplication::translate("EmergencyMainWindow", "MainWindow", nullptr));
        pb_emergency->setText(QCoreApplication::translate("EmergencyMainWindow", "Emergency Button", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmergencyMainWindow: public Ui_EmergencyMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMERGENCYWIDGET_H
