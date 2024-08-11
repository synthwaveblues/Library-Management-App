/********************************************************************************
** Form generated from reading UI file 'userpanel.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERPANEL_H
#define UI_USERPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_UserPanel
{
public:
    QLabel *label;
    QLineEdit *txtInfo;
    QPushButton *btnFind;
    QListWidget *listAviableBooks;
    QListWidget *listMyBooks;
    QLabel *label_2;
    QPushButton *btnMyAllBooks;
    QPushButton *btnAllBooks;

    void setupUi(QDialog *UserPanel)
    {
        if (UserPanel->objectName().isEmpty())
            UserPanel->setObjectName("UserPanel");
        UserPanel->resize(1160, 350);
        label = new QLabel(UserPanel);
        label->setObjectName("label");
        label->setGeometry(QRect(210, 20, 291, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Javanese Text")});
        font.setPointSize(14);
        label->setFont(font);
        txtInfo = new QLineEdit(UserPanel);
        txtInfo->setObjectName("txtInfo");
        txtInfo->setGeometry(QRect(130, 70, 341, 51));
        btnFind = new QPushButton(UserPanel);
        btnFind->setObjectName("btnFind");
        btnFind->setGeometry(QRect(190, 130, 83, 29));
        listAviableBooks = new QListWidget(UserPanel);
        listAviableBooks->setObjectName("listAviableBooks");
        listAviableBooks->setGeometry(QRect(50, 170, 501, 141));
        QFont font1;
        font1.setPointSize(12);
        listAviableBooks->setFont(font1);
        listMyBooks = new QListWidget(UserPanel);
        listMyBooks->setObjectName("listMyBooks");
        listMyBooks->setGeometry(QRect(600, 130, 501, 191));
        listMyBooks->setFont(font1);
        label_2 = new QLabel(UserPanel);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(790, 50, 131, 31));
        label_2->setFont(font);
        btnMyAllBooks = new QPushButton(UserPanel);
        btnMyAllBooks->setObjectName("btnMyAllBooks");
        btnMyAllBooks->setGeometry(QRect(810, 90, 83, 29));
        btnAllBooks = new QPushButton(UserPanel);
        btnAllBooks->setObjectName("btnAllBooks");
        btnAllBooks->setGeometry(QRect(340, 130, 83, 29));

        retranslateUi(UserPanel);

        QMetaObject::connectSlotsByName(UserPanel);
    } // setupUi

    void retranslateUi(QDialog *UserPanel)
    {
        UserPanel->setWindowTitle(QCoreApplication::translate("UserPanel", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("UserPanel", "Aviable books", nullptr));
        btnFind->setText(QCoreApplication::translate("UserPanel", "Find!", nullptr));
        label_2->setText(QCoreApplication::translate("UserPanel", "Your books", nullptr));
        btnMyAllBooks->setText(QCoreApplication::translate("UserPanel", "Refresh", nullptr));
        btnAllBooks->setText(QCoreApplication::translate("UserPanel", "Show all!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserPanel: public Ui_UserPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERPANEL_H
