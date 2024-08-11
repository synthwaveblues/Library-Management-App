#include "book.h"

Book::Book(const std::string &user, const std::string &title, const std::string &authorName, const std::string &isbn, int quantity)
    : user(user),
    title(title),
    authorName(authorName.empty() ? "Anonim" : authorName),
    isbn(isbn.empty() ? "0000-0000-0000" : isbn),
    quantity(quantity > 0 ? quantity : 0),
    borrowed(0) {}

std::string Book::getUser() const {
    return user;
}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthorName() const {
    return authorName;
}

std::string Book::getIsbn() const {
    return isbn;
}

int Book::getQuantity() const {
    return quantity;
}

int Book::getBorrowed() const {
    return borrowed;
}

void Book::decrease() {
    quantity--;
}

bool Book::operator==(const Book &other) {
    return user == other.user &&
           title == other.title &&
           authorName == other.authorName &&
           isbn == other.isbn &&
           quantity == other.quantity;
}

void Book::setQuantity(int newQuantity) {
    this->quantity = newQuantity;
}
