#pragma once

#include <string>

class Book {
private:
    int id;
    std::string title;
    std::string author;
    std::string publisher;
    int year;
    int pageCount;
    double price;
    std::string coverType;

public:
    Book();
    Book(int id, const std::string& title, const std::string& author, const std::string& publisher,
        int year, int pageCount, double price, const std::string& coverType);

    int getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getPublisher() const;
    int getYear() const;
    int getPageCount() const;
    double getPrice() const;
    std::string getCoverType() const;

    void setId(int id);
    void setTitle(const std::string& title);
    void setAuthor(const std::string& author);
    void setPublisher(const std::string& publisher);
    void setYear(int year);
    void setPageCount(int pageCount);
    void setPrice(double price);
    void setCoverType(const std::string& coverType);

    std::string encrypt(const std::string& text, int shift) const;
    std::string decrypt(const std::string& cipherText, int shift) const;

    void display() const;

};