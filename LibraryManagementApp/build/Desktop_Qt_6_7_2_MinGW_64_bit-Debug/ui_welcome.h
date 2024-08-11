/********************************************************************************
** Form generated from reading UI file 'welcome.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOME_H
#define UI_WELCOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Welcome
{
public:
    QPushButton *btnUser;
    QPushButton *btnAdmin;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *txtLogin;
    QLineEdit *txtPassword;
    QPushButton *btnCreate;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *lbl_time;

    void setupUi(QDialog *Welcome)
    {
        if (Welcome->objectName().isEmpty())
            Welcome->setObjectName("Welcome");
        Welcome->setEnabled(true);
        Welcome->resize(613, 430);
        btnUser = new QPushButton(Welcome);
        btnUser->setObjectName("btnUser");
        btnUser->setGeometry(QRect(120, 270, 151, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        btnUser->setFont(font);
        btnAdmin = new QPushButton(Welcome);
        btnAdmin->setObjectName("btnAdmin");
        btnAdmin->setGeometry(QRect(320, 270, 151, 61));
        btnAdmin->setFont(font);
        label = new QLabel(Welcome);
        label->setObjectName("label");
        label->setGeometry(QRect(230, 40, 311, 71));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Javanese Text")});
        font1.setPointSize(20);
        label->setFont(font1);
        label_2 = new QLabel(Welcome);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(140, 120, 51, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Javanese Text")});
        font2.setPointSize(12);
        label_2->setFont(font2);
        label_3 = new QLabel(Welcome);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(110, 170, 91, 31));
        label_3->setFont(font2);
        txtLogin = new QLineEdit(Welcome);
        txtLogin->setObjectName("txtLogin");
        txtLogin->setGeometry(QRect(200, 110, 241, 41));
        txtPassword = new QLineEdit(Welcome);
        txtPassword->setObjectName("txtPassword");
        txtPassword->setEnabled(true);
        txtPassword->setGeometry(QRect(200, 160, 241, 41));
        txtPassword->setEchoMode(QLineEdit::EchoMode::Password);
        btnCreate = new QPushButton(Welcome);
        btnCreate->setObjectName("btnCreate");
        btnCreate->setGeometry(QRect(260, 380, 83, 31));
        btnCreate->setFont(font);
        label_4 = new QLabel(Welcome);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(190, 350, 311, 31));
        label_4->setFont(font2);
        label_5 = new QLabel(Welcome);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(240, 210, 111, 71));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Javanese Text")});
        font3.setPointSize(16);
        label_5->setFont(font3);
        lbl_time = new QLabel(Welcome);
        lbl_time->setObjectName("lbl_time");
        lbl_time->setGeometry(QRect(490, 400, 111, 31));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Javanese Text")});
        lbl_time->setFont(font4);

        retranslateUi(Welcome);

        QMetaObject::connectSlotsByName(Welcome);
    } // setupUi

    void retranslateUi(QDialog *Welcome)
    {
        Welcome->setWindowTitle(QCoreApplication::translate("Welcome", "Dialog", nullptr));
        btnUser->setText(QCoreApplication::translate("Welcome", "User", nullptr));
        btnAdmin->setText(QCoreApplication::translate("Welcome", "Admin", nullptr));
        label->setText(QCoreApplication::translate("Welcome", "Welcome back!", nullptr));
        label_2->setText(QCoreApplication::translate("Welcome", "Login", nullptr));
        label_3->setText(QCoreApplication::translate("Welcome", "Password", nullptr));
        txtPassword->setText(QString());
        btnCreate->setText(QCoreApplication::translate("Welcome", "Create!", nullptr));
        label_4->setText(QCoreApplication::translate("Welcome", "Don't have user account? Create it!", nullptr));
        label_5->setText(QCoreApplication::translate("Welcome", "Login as:", nullptr));
        lbl_time->setText(QCoreApplication::translate("Welcome", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Welcome: public Ui_Welcome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOME_H
