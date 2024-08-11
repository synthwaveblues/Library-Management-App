// bookmanager.h
#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H

#include <string>
#include <vector>
#include "book.h"

class BookManager {
public:
    BookManager(std::string path_);
    std::string getPath() const;
    int getBooksSize() const;
    std::vector<Book> getBooks() const;
    void saveBook(const Book &book, const std::string &user);
    void removeBook(Book &bookToRemove);
    void loadBooks();
    void clearBooks();
    bool checkBook(const Book &book) const;
    BookManager& operator=(const BookManager& other);
    void updateBookQuantity(Book &bookToUpdate, int value);
    static std::string stringToLower(const std::string &str);

private:
    std::string path;
    std::vector<Book> books;


};

#endif // BOOKMANAGER_H
