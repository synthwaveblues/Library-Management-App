/********************************************************************************
** Form generated from reading UI file 'adminpanel.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINPANEL_H
#define UI_ADMINPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AdminPanel
{
public:
    QLabel *label;
    QLineEdit *txtTitle;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *txtAuthorName;
    QLabel *label_5;
    QLineEdit *txtISBN;
    QLineEdit *txtQuantity;
    QLabel *label_6;
    QPushButton *btnAddBook;
    QLabel *label_7;
    QPushButton *btnShowBooks;
    QPushButton *btnDelete;
    QListWidget *listAllBooks;
    QPushButton *btnList;

    void setupUi(QDialog *AdminPanel)
    {
        if (AdminPanel->objectName().isEmpty())
            AdminPanel->setObjectName("AdminPanel");
        AdminPanel->resize(1080, 417);
        QFont font;
        font.setPointSize(13);
        AdminPanel->setFont(font);
        label = new QLabel(AdminPanel);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 90, 131, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Javanese Text")});
        font1.setPointSize(16);
        label->setFont(font1);
        txtTitle = new QLineEdit(AdminPanel);
        txtTitle->setObjectName("txtTitle");
        txtTitle->setGeometry(QRect(250, 90, 201, 28));
        label_2 = new QLabel(AdminPanel);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(160, 20, 361, 41));
        label_2->setFont(font1);
        label_3 = new QLabel(AdminPanel);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 140, 221, 41));
        label_3->setFont(font1);
        txtAuthorName = new QLineEdit(AdminPanel);
        txtAuthorName->setObjectName("txtAuthorName");
        txtAuthorName->setGeometry(QRect(250, 140, 201, 28));
        label_5 = new QLabel(AdminPanel);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(60, 190, 71, 41));
        label_5->setFont(font1);
        txtISBN = new QLineEdit(AdminPanel);
        txtISBN->setObjectName("txtISBN");
        txtISBN->setGeometry(QRect(250, 190, 201, 28));
        txtQuantity = new QLineEdit(AdminPanel);
        txtQuantity->setObjectName("txtQuantity");
        txtQuantity->setGeometry(QRect(250, 240, 201, 28));
        label_6 = new QLabel(AdminPanel);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(60, 240, 121, 41));
        label_6->setFont(font1);
        btnAddBook = new QPushButton(AdminPanel);
        btnAddBook->setObjectName("btnAddBook");
        btnAddBook->setGeometry(QRect(120, 310, 111, 31));
        QFont font2;
        font2.setPointSize(11);
        btnAddBook->setFont(font2);
        label_7 = new QLabel(AdminPanel);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(720, 10, 151, 41));
        label_7->setFont(font1);
        btnShowBooks = new QPushButton(AdminPanel);
        btnShowBooks->setObjectName("btnShowBooks");
        btnShowBooks->setGeometry(QRect(260, 310, 151, 31));
        btnShowBooks->setFont(font2);
        btnDelete = new QPushButton(AdminPanel);
        btnDelete->setObjectName("btnDelete");
        btnDelete->setGeometry(QRect(770, 350, 181, 29));
        btnDelete->setFont(font2);
        listAllBooks = new QListWidget(AdminPanel);
        listAllBooks->setObjectName("listAllBooks");
        listAllBooks->setGeometry(QRect(570, 50, 431, 281));
        btnList = new QPushButton(AdminPanel);
        btnList->setObjectName("btnList");
        btnList->setGeometry(QRect(630, 350, 111, 31));
        btnList->setFont(font2);

        retranslateUi(AdminPanel);

        QMetaObject::connectSlotsByName(AdminPanel);
    } // setupUi

    void retranslateUi(QDialog *AdminPanel)
    {
        AdminPanel->setWindowTitle(QCoreApplication::translate("AdminPanel", "Widget", nullptr));
        label->setText(QCoreApplication::translate("AdminPanel", "Book title:", nullptr));
        label_2->setText(QCoreApplication::translate("AdminPanel", "Add a new book to library:", nullptr));
        label_3->setText(QCoreApplication::translate("AdminPanel", "Author's name:", nullptr));
        label_5->setText(QCoreApplication::translate("AdminPanel", "ISBN:", nullptr));
        label_6->setText(QCoreApplication::translate("AdminPanel", "Quantity:", nullptr));
        btnAddBook->setText(QCoreApplication::translate("AdminPanel", "Add", nullptr));
        label_7->setText(QCoreApplication::translate("AdminPanel", "Saved books:", nullptr));
        btnShowBooks->setText(QCoreApplication::translate("AdminPanel", "Show all books", nullptr));
        btnDelete->setText(QCoreApplication::translate("AdminPanel", "Clear data", nullptr));
        btnList->setText(QCoreApplication::translate("AdminPanel", "Activity list", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminPanel: public Ui_AdminPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINPANEL_H
