#include "book.h"
#include <iostream>

using namespace std;

Book::Book() : id(0), year(0), pageCount(0), price(0.0) {}

Book::Book(int id, const std::string& title, const std::string& author, const std::string& publisher,
    int year, int pageCount, double price, const std::string& coverType)
    : id(id), title(title), author(author), publisher(publisher), year(year),
    pageCount(pageCount), price(price), coverType(coverType) {}

int Book::getId() const {
    return id;
}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

std::string Book::getPublisher() const {
    return publisher;
}

int Book::getYear() const {
    return year;
}

int Book::getPageCount() const {
    return pageCount;
}

double Book::getPrice() const {
    return price;
}

std::string Book::getCoverType() const {
    return coverType;
}

void Book::setId(int id) {
    this->id = id;
}

void Book::setTitle(const std::string& title) {
    this->title = title;
}

void Book::setAuthor(const std::string& author) {
    this->author = author;
}

void Book::setPublisher(const std::string& publisher) {
    this->publisher = publisher;
}

void Book::setYear(int year) {
    this->year = year;
}

void Book::setPageCount(int pageCount) {
    this->pageCount = pageCount;
}

void Book::setPrice(double price) {
    this->price = price;
}

void Book::setCoverType(const string& coverType) {
    this->coverType = coverType;
}

string Book::encrypt(const string& text, int shift) const {
    string result = text;
    for (char& c : result) {
        if (isalpha(c)) {
            if (isupper(c)) {
                c = 'A' + (c - 'A' + shift) % 26;
            }
            else {
                c = 'a' + (c - 'a' + shift) % 26;
            }
        }
    }
    return result;
}

std::string Book::decrypt(const string& cipherText, int shift) const {
    return encrypt(cipherText, 26 - shift);
}

void Book::display() const {
    cout << "ID: " << id << "\n";
    cout << "Title: " << title << "\n";
    cout << "Author: " << author << "\n";
    cout << "Publisher: " << publisher << "\n";
    cout << "Year: " << year << "\n";
    cout << "Page Count: " << pageCount << "\n";
    cout << "Price: " << price << "\n";
    cout << "Cover Type: " << coverType << "\n";
    cout << "-------------------------\n";
}