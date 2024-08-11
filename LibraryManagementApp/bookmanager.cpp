#include "bookmanager.h"
#include "book.h"
#include "qdebug.h"
#include "qlogging.h"
#include <fstream>
#include <sstream>
#include <algorithm>

// Constructor for BookManager
BookManager::BookManager(std::string path_)
    : path(std::move(path_)) {}  // Use std::move to avoid unnecessary copying

// Getter for path
std::string BookManager::getPath() const {
    return path;
}

// Getter for number of books
int BookManager::getBooksSize() const  {
    return books.size();
}

// Getter for the list of books
std::vector<Book> BookManager::getBooks() const  {
    return books;
}

// Function to convert a string to lowercase
std::string BookManager::stringToLower(const std::string &str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// Save a book to the file
void BookManager::saveBook(const Book &book, const std::string &user) {
    std::ofstream file(path, std::ios::app);
    if (file.is_open()) {
        file << user << "," << book.getTitle() << "," << book.getAuthorName() << "," << book.getIsbn() << "," << book.getQuantity() << "\n";
        file.close();
    } else {
        qDebug() << "Unable to open file for writing.";
    }
}

// Remove a book from the file
void BookManager::removeBook(Book &bookToRemove) {
    std::ifstream inFile(path);
    if (!inFile.is_open()) {
        qDebug() << "Unable to open file for reading.";
        return;
    }

    std::vector<std::string> lines;
    bool bookRemoved = false;

    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        std::string user, title, author, isbn, quantityStr;

        if (std::getline(iss, user, ',') &&
            std::getline(iss, title, ',') &&
            std::getline(iss, author, ',') &&
            std::getline(iss, isbn, ',') &&
            std::getline(iss, quantityStr)) {

            int quantity = std::stoi(quantityStr);

            // Create a book object from the current line
            Book currentBook(user, title, author, isbn, quantity);

            if (currentBook == bookToRemove) {
                bookRemoved = true;  // Mark that the book was removed
                continue;  // Skip adding this line to the new file, effectively removing it
            }

            lines.push_back(line);  // Add the line to the list if the book doesn't match
        }
    }

    inFile.close();

    if (!bookRemoved) {
        qDebug() << "Book not found in the user's collection.";
        return;
    }

    std::ofstream outFile(path);
    if (!outFile.is_open()) {
        qDebug() << "Unable to open file for writing.";
        return;
    }

    for (const auto &line : lines) {
        outFile << line << "\n";
    }

    outFile.close();

    loadBooks();  // Reload books after modification
}

// Load books from the file
void BookManager::loadBooks() {
    books.clear();
    std::ifstream file(path);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string user, title, author, isbn;
            int quantity;

            std::getline(ss, user, ',');
            std::getline(ss, title, ',');
            std::getline(ss, author, ',');
            std::getline(ss, isbn, ',');
            ss >> quantity;

            Book book(user, title, author, isbn, quantity);
            books.push_back(book);
        }
        file.close();
    } else {
        qDebug() << "Unable to open file for reading.";
    }
}

// Clear all books from the file
void BookManager::clearBooks() {
    std::ofstream file(path, std::ios::out | std::ios::trunc);
    if (file.is_open()) {
        file.close();
    } else {
        qDebug() << "Unable to open file " << QString::fromStdString(path);
    }
    books.clear();
}

// Check if a book already exists in the list
bool BookManager::checkBook(const Book &book) const {  // true - not the same, false - is the same
    std::string bookTitleLower = stringToLower(book.getTitle());
    for(const auto &b : books) {
        if(stringToLower(b.getTitle()) == bookTitleLower) {
            return false;
        }
    }
    return true;
}

// Assignment operator overload
BookManager& BookManager::operator=(const BookManager& other) {
    if (this != &other) {
        books = other.books;
        path = other.path;
    }
    return *this;
}

// Update the quantity of a book in the file
void BookManager::updateBookQuantity(Book &bookToUpdate, int value) {
    std::ifstream inFile(path);
    if (!inFile.is_open()) {
        qDebug() << "Unable to open file for reading.";
        return;
    }

    std::vector<std::string> lines;
    bool bookFound = false;
    std::string line;

    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        std::string user, title, author, isbn, quantityStr;

        if (std::getline(iss, user, ',') &&
            std::getline(iss, title, ',') &&
            std::getline(iss, author, ',') &&
            std::getline(iss, isbn, ',') &&
            std::getline(iss, quantityStr)) {

            int quantity = std::stoi(quantityStr);

            if (stringToLower(title) == stringToLower(bookToUpdate.getTitle()) &&
                stringToLower(author) == stringToLower(bookToUpdate.getAuthorName()) &&
                isbn == bookToUpdate.getIsbn()) {
                quantity += value;
                bookFound = true;
            }

            lines.push_back(user + "," + title + "," + author + "," + isbn + "," + std::to_string(quantity));
        }
    }

    inFile.close();

    if (!bookFound) {
        qDebug() << "Book not found in the collection.";
        return;
    }

    std::ofstream outFile(path);
    if (!outFile.is_open()) {
        qDebug() << "Unable to open file for writing.";
        return;
    }

    for (const auto &line : lines) {
        outFile << line << "\n";
    }

    outFile.close();

    loadBooks();
}
