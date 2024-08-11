#include "adminpanel.h"
#include "activitylist.h"
#include "book.h"
#include "bookmanager.h"
#include "ui_adminpanel.h"
#include <QMessageBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFileDialog>

AdminPanel::AdminPanel(BookManager bookManager_, std::string login, QDialog *parent)
    : QDialog(parent)
    , ui(new Ui::AdminPanel)
    , bookManager(bookManager_)
    , admin(login)
    , activityList(nullptr)
{
    ui->setupUi(this);
    on_btnShowBooks_clicked();
    activityList = new ActivityList(bookManager, this);

    QString activityMessage = QString("Admin \"%1\" has been logged - %2")
                                 .arg(QString::fromStdString(admin))
                                 .arg(currentDateTime().toString("HH:mm dd.MM.yyyy"));
    activityList->addToList(activityMessage);
}

AdminPanel::~AdminPanel()
{
    delete ui;
    delete activityList;
}

QDateTime AdminPanel::currentDateTime()
{
    return QDateTime::currentDateTime();
}

void AdminPanel::on_btnAddBook_clicked()
{
    bookManager.loadBooks();
    Book book("Lib", ui->txtTitle->text().toStdString(), ui->txtAuthorName->text().toStdString(), ui->txtISBN->text().toStdString(), ui->txtQuantity->text().toInt());

    if (ui->txtQuantity->text().toInt() == 0) // setting default quantity to 1
        book.setQuantity(1);

    if (bookManager.checkBook(book) && !book.getTitle().empty()) { // checking if this book is already in our array
        bookManager.saveBook(book, "Lib");
        clearInputFields();
        on_btnShowBooks_clicked();

        // Log the action to ActivityList
        if (activityList) {
            QString activityMessage = QString("Book \"%1\" was added by admin \"%2\" - %3")
                .arg(QString::fromStdString(book.getTitle()))
                .arg(QString::fromStdString(admin))
                .arg(currentDateTime().toString("HH:mm dd.MM.yyyy"));

            // Add the formatted message to the activity list
            activityList->addToList(activityMessage);
        }

    } else {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Add a book");
        msgBox.setInformativeText("This book is already in your collection. Do you want to add one more?");
        msgBox.setStandardButtons(QMessageBox::No | QMessageBox::Yes);

        int ret = msgBox.exec();

        if (ret == QMessageBox::Yes) {
            bookManager.updateBookQuantity(book, 1);  // Increase the quantity by 1
            clearInputFields();
            on_btnShowBooks_clicked();

            // Log the action to ActivityList
            if (activityList) {
                QString activityMessage = QString("Book \"%1\" quantity increased by 1 by admin \"%2\" - %3")
                .arg(QString::fromStdString(book.getTitle()))
                    .arg(QString::fromStdString(admin))
                    .arg(currentDateTime().toString("HH:mm dd.MM.yyyy"));

                // Add the formatted message to the activity list
                activityList->addToList(activityMessage);
            }
        }
    }
}

void AdminPanel::on_btnShowBooks_clicked()
{
    ui->listAllBooks->clear();
    bookManager.loadBooks();
    for (int i = 0; i < bookManager.getBooksSize(); i++) {
        QString title = QString::fromStdString(bookManager.getBooks()[i].getTitle());
        QString author = QString::fromStdString(bookManager.getBooks()[i].getAuthorName());
        QString quantity = QString::number(bookManager.getBooks()[i].getQuantity());
        ui->listAllBooks->addItem(QString::number(i + 1) + ". \"" + title + "\" written by " + author + ". Availability: " + quantity);
    }
}

void AdminPanel::clearInputFields()
{
    ui->txtTitle->clear();
    ui->txtAuthorName->clear();
    ui->txtISBN->clear();
    ui->txtQuantity->clear();
}

void AdminPanel::showError(const QString &message) {
    QMessageBox::critical(nullptr, "Error", message);
}



void AdminPanel::on_btnDelete_clicked()
{
    bookManager.clearBooks();
    on_btnShowBooks_clicked();

    if (activityList) {
        QString activityMessage = QString("All books have been deleted from the collection by the admin \"%1\" - %2")
            .arg(QString::fromStdString(admin))
            .arg(currentDateTime().toString("HH:mm dd.MM.yyyy"));

        // Add the formatted message to the activity list
        activityList->addToList(activityMessage);
    }
}

void AdminPanel::on_btnList_clicked()
{
    activityList->show();
}
