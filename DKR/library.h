#pragma once

#include "book.h"
#include <vector>
#include <fstream>

class Library {
private:
    std::vector<Book> books;
    std::string filename;
    std::string logFilename; // Назва файлу для логу

    void writeLog(const std::string& message) const;

public:
    Library(const std::string& filename, const std::string& logFilename);

    void addBook(const Book& book);
    void saveToFile() const;
    void loadFromFile();
    void displayBooksByAuthor(const std::string& author) const;
    void displayBooksByPublisher(const std::string& publisher) const;
    void displayBooksPublishedAfter(int year) const;
};
