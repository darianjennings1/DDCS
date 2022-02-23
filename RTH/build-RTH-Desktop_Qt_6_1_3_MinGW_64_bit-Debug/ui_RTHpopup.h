/********************************************************************************
** Form generated from reading UI file 'RTHpopup.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RTHPOPUP_H
#define UI_RTHPOPUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RTHpopup
{
public:
    QWidget *widget;
    QDialogButtonBox *ConfimationButton;
    QTextBrowser *textBrowser;
    QLabel *label;

    void setupUi(QWidget *RTHpopup)
    {
        if (RTHpopup->objectName().isEmpty())
            RTHpopup->setObjectName(QString::fromUtf8("RTHpopup"));
        RTHpopup->resize(400, 300);
        RTHpopup->setAutoFillBackground(false);
        widget = new QWidget(RTHpopup);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(70, 40, 261, 201));
        ConfimationButton = new QDialogButtonBox(widget);
        ConfimationButton->setObjectName(QString::fromUtf8("ConfimationButton"));
        ConfimationButton->setGeometry(QRect(50, 140, 171, 71));
        ConfimationButton->setBaseSize(QSize(0, 0));
        ConfimationButton->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Yes);
        textBrowser = new QTextBrowser(widget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(20, 50, 261, 111));
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
        label->setGeometry(QRect(80, 10, 161, 41));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        label->setFont(font1);

        retranslateUi(RTHpopup);

        QMetaObject::connectSlotsByName(RTHpopup);
    } // setupUi

    void retranslateUi(QWidget *RTHpopup)
    {
        RTHpopup->setWindowTitle(QCoreApplication::translate("RTHpopup", "Form", nullptr));
        textBrowser->setMarkdown(QCoreApplication::translate("RTHpopup", "The return button has been pushed, would you like to continue return to home\n"
"protocol?\n"
"\n"
"", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("RTHpopup", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:16pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:10px; margin-bottom:10px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">The return button has been pushed, would you like to continue return to home protocol?</p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("RTHpopup", "Notice!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RTHpopup: public Ui_RTHpopup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RTHPOPUP_H
