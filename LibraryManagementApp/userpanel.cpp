#include "userpanel.h"
#include "ui_userpanel.h"
#include <QMessageBox>
#include <algorithm>
#include <string>
#include <QDateTime>

UserPanel::UserPanel(BookManager bookManager_, BookManager userManager_, std::string login, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserPanel)
    , bookManager(bookManager_)
    , userBookManager(userManager_)
    , user(login)
{
    ui->setupUi(this);
    on_btnAllBooks_clicked();
    on_btnMyAllBooks_clicked();
}

UserPanel::~UserPanel()
{
    delete ui;
}

void UserPanel::on_btn_clicked()
{
    bookManager.loadBooks();
    ui->listAviableBooks->clear();
    std::string data = ui->txtInfo->text().toStdString();

    // Convert the input data to lowercase
    std::transform(data.begin(), data.end(), data.begin(), ::tolower);

    for(int i = 0; i < bookManager.getBooksSize(); i++) {
        // Get book details and convert them to lowercase
        std::string title = bookManager.getBooks()[i].getTitle();
        std::string author = bookManager.getBooks()[i].getAuthorName();
        std::string isbn = bookManager.getBooks()[i].getIsbn();

        std::transform(title.begin(), title.end(), title.begin(), ::tolower);
        std::transform(author.begin(), author.end(), author.begin(), ::tolower);
        std::transform(isbn.begin(), isbn.end(), isbn.begin(), ::tolower);

        if(title == data || author == data || isbn == data) {
            QString title = QString::fromStdString(bookManager.getBooks()[i].getTitle());
            QString author = QString::fromStdString(bookManager.getBooks()[i].getAuthorName());
            QString quantity = QString::number(bookManager.getBooks()[i].getQuantity());
            if(bookManager.getBooks()[i].getQuantity() != 0)
                ui->listAviableBooks->addItem("\"" + title + "\" written by " + author + ". Availability: " + quantity);
        }
    }
}

void UserPanel::on_listAviableBooks_itemDoubleClicked(QListWidgetItem *item) {
    QString itemText = item->text();
    QString title = itemText.section("\"", 1, 1);

    std::string searchTitle = title.toStdString();
    std::transform(searchTitle.begin(), searchTitle.end(), searchTitle.begin(), ::tolower);

    bookManager.loadBooks();
    for (int i = 0; i < bookManager.getBooksSize(); i++) {
        std::string bookTitle = bookManager.getBooks()[i].getTitle();
        std::transform(bookTitle.begin(), bookTitle.end(), bookTitle.begin(), ::tolower);

        if (bookTitle == searchTitle) {
            QString author = QString::fromStdString(bookManager.getBooks()[i].getAuthorName());
            QString isbn = QString::fromStdString(bookManager.getBooks()[i].getIsbn());
            QString quantity = QString::number(bookManager.getBooks()[i].getQuantity());

            QString details = "Title: " + title + "\nAuthor: " + author + "\nISBN: " + isbn + "\nQuantity: " + quantity;

            QMessageBox msgBox;
            msgBox.setText(details);
            msgBox.setWindowTitle("Borrow book");
            msgBox.setInformativeText("Do you want to borrow this book for your collection?");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setButtonText(QMessageBox::Yes, "Borrow");
            msgBox.setButtonText(QMessageBox::No, "Exit");

            int ret = msgBox.exec();

            if (ret == QMessageBox::Yes) {
                bookManager.updateBookQuantity(bookManager.getBooks()[i], -1);

                Book myBook = bookManager.getBooks()[i];
                if(userBookManager.checkBook(myBook)) {
                    myBook.setQuantity(1);
                    userBookManager.saveBook(myBook, user);
                    on_btnAllBooks_clicked();
                    on_btnMyAllBooks_clicked();
                }
                else {
                    QMessageBox msgBox;
                    msgBox.setWindowTitle("Add a book");
                    msgBox.setInformativeText("This book is already in your collection. Do you want to get one more?");
                    msgBox.setStandardButtons(QMessageBox::No | QMessageBox::Yes);

                    int ret = msgBox.exec();

                    if (ret == QMessageBox::Yes) {
                        userBookManager.updateBookQuantity(myBook, 1);  // Increase the quantity by 1
                        on_btnMyAllBooks_clicked();
                    }
                }

                on_btnAllBooks_clicked();
            }
            break;
        }
    }
}

void UserPanel::on_listMyBooks_itemDoubleClicked(QListWidgetItem *item) {
    QString itemText = item->text();
    QString title = itemText.section("\"", 1, 1);

    std::string searchTitle = title.toStdString();
    std::transform(searchTitle.begin(), searchTitle.end(), searchTitle.begin(), ::tolower);

    userBookManager.loadBooks();
    for (int i = 0; i < userBookManager.getBooksSize(); i++) {
        std::string bookTitle = userBookManager.getBooks()[i].getTitle();
        std::transform(bookTitle.begin(), bookTitle.end(), bookTitle.begin(), ::tolower);

        if (bookTitle == searchTitle) {
            QString author = QString::fromStdString(userBookManager.getBooks()[i].getAuthorName());
            QString isbn = QString::fromStdString(userBookManager.getBooks()[i].getIsbn());
            QString quantity = QString::number(userBookManager.getBooks()[i].getQuantity());

            QString details = "Title: " + title + "\nAuthor: " + author + "\nISBN: " + isbn + "\nQuantity: " + quantity;

            QMessageBox msgBox;
            msgBox.setText(details);
            msgBox.setWindowTitle("Return book");
            msgBox.setInformativeText("Do you want to return this book to the library?");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setButtonText(QMessageBox::Yes, "Return");
            msgBox.setButtonText(QMessageBox::No, "Exit");

            int ret = msgBox.exec();

            if (ret == QMessageBox::Yes) {
                Book bookToReturn = userBookManager.getBooks()[i];

                // Update the user book quantity
                if (bookToReturn.getQuantity() > 1) {
                    userBookManager.updateBookQuantity(bookToReturn, -1);
                } else {
                    userBookManager.removeBook(bookToReturn);
                }

                // Update the main library book quantity
                bookManager.loadBooks();
                bool found = false;
                for (int j = 0; j < bookManager.getBooksSize(); j++) {
                    if (bookManager.stringToLower(bookManager.getBooks()[j].getTitle()) == bookManager.stringToLower(bookToReturn.getTitle())) {
                        bookManager.updateBookQuantity(bookManager.getBooks()[j], 1);
                        found = true;
                        break;
                    }
                }

                // If the book wasn't found in the library collection, re-add it
                if (!found) {
                    bookToReturn.setQuantity(1);
                    bookManager.saveBook(bookToReturn, "");
                }

                on_btnMyAllBooks_clicked();
                on_btnAllBooks_clicked();
            }
            break;
        }
    }
}

void UserPanel::on_btnAllBooks_clicked()
{
    bookManager.loadBooks();
    ui->listAviableBooks->clear();

    for(int i = 0; i < bookManager.getBooksSize(); i++) {
        QString title = QString::fromStdString(bookManager.getBooks()[i].getTitle());
        QString author = QString::fromStdString(bookManager.getBooks()[i].getAuthorName());
        QString quantity = QString::number(bookManager.getBooks()[i].getQuantity());
        if(bookManager.getBooks()[i].getQuantity() != 0)
            ui->listAviableBooks->addItem("\"" + title + "\" written by " + author + ". Availability: " + quantity);
    }
}

void UserPanel::on_btnMyAllBooks_clicked()
{
    ui->listMyBooks->clear();
    userBookManager.loadBooks();
    int j = 0;
    for(int i = 0; i < userBookManager.getBooksSize(); i++){
        if(userBookManager.getBooks()[i].getUser() == user){
            QString title = QString::fromStdString(userBookManager.getBooks()[i].getTitle());
            QString author = QString::fromStdString(userBookManager.getBooks()[i].getAuthorName());
            QString quantity = QString::number(userBookManager.getBooks()[i].getQuantity());
            ui->listMyBooks->addItem(QString::number(j + 1) + ". \"" + title + "\" written by " + author + ". Availability: " + quantity);
            j++;
        }
    }
}
