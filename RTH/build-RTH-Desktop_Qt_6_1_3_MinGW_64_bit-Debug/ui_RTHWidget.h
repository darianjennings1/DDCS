/********************************************************************************
** Form generated from reading UI file 'RTHWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RTHWIDGET_H
#define UI_RTHWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RTHMainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pb_RTH;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RTHMainWindow)
    {
        if (RTHMainWindow->objectName().isEmpty())
            RTHMainWindow->setObjectName(QString::fromUtf8("RTHMainWindow"));
        RTHMainWindow->resize(800, 600);
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        RTHMainWindow->setPalette(palette);
        centralwidget = new QWidget(RTHMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(120, 60, 201, 171));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pb_RTH = new QPushButton(widget);
        pb_RTH->setObjectName(QString::fromUtf8("pb_RTH"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pb_RTH->sizePolicy().hasHeightForWidth());
        pb_RTH->setSizePolicy(sizePolicy);
        pb_RTH->setMinimumSize(QSize(104, 104));
        pb_RTH->setMaximumSize(QSize(104, 104));
        QPalette palette1;
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        QBrush brush2(QColor(0, 0, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush2);
        QBrush brush3(QColor(255, 255, 255, 128));
        brush3.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        QBrush brush4(QColor(255, 255, 255, 128));
        brush4.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        QBrush brush5(QColor(255, 255, 255, 128));
        brush5.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        pb_RTH->setPalette(palette1);
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        pb_RTH->setFont(font);
        pb_RTH->setAutoFillBackground(false);
        pb_RTH->setStyleSheet(QString::fromUtf8(" background-color: blue;\n"
"color: rgb(255, 255, 255);\n"
" border-style: solid;\n"
" border-width:2px;\n"
" border-radius:50px;\n"
" border-color: black;\n"
" max-width:100px;\n"
" max-height:100px;\n"
" min-width:100px;\n"
" min-height:100px;"));
        pb_RTH->setIconSize(QSize(20, 20));
        pb_RTH->setFlat(true);

        horizontalLayout->addWidget(pb_RTH);

        RTHMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RTHMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        RTHMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(RTHMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        RTHMainWindow->setStatusBar(statusbar);

        retranslateUi(RTHMainWindow);

        QMetaObject::connectSlotsByName(RTHMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RTHMainWindow)
    {
        RTHMainWindow->setWindowTitle(QCoreApplication::translate("RTHMainWindow", "MainWindow", nullptr));
        pb_RTH->setText(QCoreApplication::translate("RTHMainWindow", "Return to\n"
"Home", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RTHMainWindow: public Ui_RTHMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RTHWIDGET_H
