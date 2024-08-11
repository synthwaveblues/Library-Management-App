/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Widget
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
    QTextEdit *txtAllBooks;
    QPushButton *btnDelete;

    void setupUi(QDialog *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1234, 417);
        QFont font;
        font.setPointSize(13);
        Widget->setFont(font);
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 60, 121, 41));
        QFont font1;
        font1.setPointSize(15);
        label->setFont(font1);
        txtTitle = new QLineEdit(Widget);
        txtTitle->setObjectName("txtTitle");
        txtTitle->setGeometry(QRect(330, 70, 201, 28));
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(160, 10, 361, 41));
        label_2->setFont(font1);
        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 110, 221, 41));
        label_3->setFont(font1);
        txtAuthorName = new QLineEdit(Widget);
        txtAuthorName->setObjectName("txtAuthorName");
        txtAuthorName->setGeometry(QRect(330, 120, 201, 28));
        label_5 = new QLabel(Widget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(60, 160, 71, 41));
        label_5->setFont(font1);
        txtISBN = new QLineEdit(Widget);
        txtISBN->setObjectName("txtISBN");
        txtISBN->setGeometry(QRect(330, 170, 201, 28));
        txtQuantity = new QLineEdit(Widget);
        txtQuantity->setObjectName("txtQuantity");
        txtQuantity->setGeometry(QRect(330, 220, 201, 28));
        label_6 = new QLabel(Widget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(60, 210, 121, 41));
        label_6->setFont(font1);
        btnAddBook = new QPushButton(Widget);
        btnAddBook->setObjectName("btnAddBook");
        btnAddBook->setGeometry(QRect(130, 280, 141, 41));
        label_7 = new QLabel(Widget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(860, 10, 151, 41));
        label_7->setFont(font1);
        btnShowBooks = new QPushButton(Widget);
        btnShowBooks->setObjectName("btnShowBooks");
        btnShowBooks->setGeometry(QRect(330, 280, 191, 41));
        txtAllBooks = new QTextEdit(Widget);
        txtAllBooks->setObjectName("txtAllBooks");
        txtAllBooks->setGeometry(QRect(720, 50, 441, 291));
        txtAllBooks->setReadOnly(true);
        btnDelete = new QPushButton(Widget);
        btnDelete->setObjectName("btnDelete");
        btnDelete->setGeometry(QRect(850, 350, 181, 29));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QDialog *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Book title:", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Add a new book to library:", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "Author's name:", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "ISBN:", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "Quantity:", nullptr));
        btnAddBook->setText(QCoreApplication::translate("Widget", "Add", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "Saved books:", nullptr));
        btnShowBooks->setText(QCoreApplication::translate("Widget", "Show all books", nullptr));
        btnDelete->setText(QCoreApplication::translate("Widget", "Clear data", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
