/********************************************************************************
** Form generated from reading UI file 'powerpopup.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POWERPOPUP_H
#define UI_POWERPOPUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_powerpopup
{
public:
    QWidget *widget;
    QTextBrowser *textBrowser;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *powerpopup)
    {
        if (powerpopup->objectName().isEmpty())
            powerpopup->setObjectName(QString::fromUtf8("powerpopup"));
        powerpopup->resize(400, 300);
        powerpopup->setAutoFillBackground(false);
        widget = new QWidget(powerpopup);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(70, 40, 261, 201));
        textBrowser = new QTextBrowser(widget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(50, 70, 221, 61));
        QFont font;
        font.setPointSize(16);
        textBrowser->setFont(font);
        textBrowser->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        textBrowser->setFrameShape(QFrame::NoFrame);
        textBrowser->setFrameShadow(QFrame::Plain);
        textBrowser->setLineWidth(0);
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 10, 181, 41));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        label->setFont(font1);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(80, 150, 91, 31));
        QFont font2;
        font2.setPointSize(11);
        pushButton->setFont(font2);

        retranslateUi(powerpopup);

        QMetaObject::connectSlotsByName(powerpopup);
    } // setupUi

    void retranslateUi(QWidget *powerpopup)
    {
        powerpopup->setWindowTitle(QCoreApplication::translate("powerpopup", "Form", nullptr));
        textBrowser->setMarkdown(QCoreApplication::translate("powerpopup", "The battery has reached 20%.\n"
"\n"
"", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("powerpopup", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:16pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:10px; margin-bottom:10px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">The battery has reached 20%.</p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("powerpopup", "Power Alert!", nullptr));
        pushButton->setText(QCoreApplication::translate("powerpopup", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class powerpopup: public Ui_powerpopup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POWERPOPUP_H
