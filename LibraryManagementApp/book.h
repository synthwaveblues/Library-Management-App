#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:
    Book(const std::string &user, const std::string &title, const std::string &authorName, const std::string &isbn, int quantity);
    std::string getUser() const;
    std::string getTitle() const;
    std::string getAuthorName() const;
    std::string getIsbn() const;
    int getQuantity() const;
    int getBorrowed() const;
    void decrease();
    bool operator==(const Book &other);
    void setQuantity(int newQuantity);

private:
    std::string user;
    std::string title;
    std::string authorName;
    std::string isbn;
    int quantity;
    int borrowed;
};

#endif // BOOK_H
