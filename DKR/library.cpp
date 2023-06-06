#include "Library.h"
#include <iostream>
#include <ctime>
using namespace std;

Library::Library(const string& filename, const string& logFilename)
    : filename(filename), logFilename(logFilename)
{
    loadFromFile();
}

void Library::addBook(const Book& book) {
    books.push_back(book);
    //cout << "Added book: " << book.getTitle() << endl;
    writeLog("Added book: " + book.getTitle());
}

void Library::saveToFile() const {
    ofstream file(filename);
    if (file.is_open()) {
        for (const Book& book : books) {
            file << book.encrypt(to_string(book.getId()), 1) << ","
                << book.encrypt(book.getTitle(), 1) << ","
                << book.encrypt(book.getAuthor(), 1) << ","
                << book.encrypt(book.getPublisher(), 1) << ","
                << book.encrypt(to_string(book.getYear()), 1) << ","
                << book.encrypt(to_string(book.getPageCount()), 1) << ","
                << book.encrypt(to_string(book.getPrice()), 1) << ","
                << book.encrypt(book.getCoverType(), 1) << "\n";
        }
        file.close();
        //cout << "Books saved to file: " << filename << endl;
        writeLog("Saved books to file: " + filename);
    }
    else {
        cerr << "Error opening file: " << filename << endl;
        writeLog("Failed to save books to file: " + filename);
    }
}

void Library::loadFromFile() {
    ifstream file(filename);
    if (file.is_open()) {
        books.clear();
        string line;
        while (getline(file, line)) {
            string id, title, author, publisher, year, pageCount, price, coverType;
            size_t pos = 0;
            string delimiter = ",";
            int shift = 1;

            id = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());

            title = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());

            author = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());

            publisher = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());

            year = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());

            pageCount = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());

            price = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());

            coverType = line;

            books.emplace_back(stoi(id),
                title,
                author,
                publisher,
                stoi(year),
                stoi(pageCount),
                stod(price),
                coverType);
        }
        file.close();
        //cout << "Books loaded from file: " << filename << endl;
        writeLog("Loaded books from file: " + filename);
    }
    else {
        cerr << "Error opening file: " << filename << endl;
        writeLog("Failed to load books from file: " + filename);
    }
}

void Library::writeLog(const string& message) const {
    ofstream file(logFilename, ios::app);
    if (file.is_open()) {
        time_t now = time(nullptr);
        char timestamp[20];
        tm localTime;
        if (localtime_s(&localTime, &now) == 0) {
            strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", &localTime);
            file << "[" << timestamp << "] " << message << "\n";
        }
        else {
            cerr << "Error getting local time." << endl;
        }
        file.close();
    }
    else {
        cerr << "Error opening log file: " << logFilename << endl;
    }
}

void Library::displayBooksByAuthor(const string& author) const {
    cout << "Books by " << author << ":" << endl;
    for (const auto& book : books) {
        if (book.getAuthor() == author) {
            book.display();
            cout << endl;
        }
    }
}

void Library::displayBooksByPublisher(const string& publisher) const {
    cout << "Books published by " << publisher << ":" << endl;
    for (const auto& book : books) {
        if (book.getPublisher() == publisher) {
            book.display();
            cout << endl;
        }
    }
}

void Library::displayBooksPublishedAfter(int year) const {
    cout << "Books published after " << year << ":" << endl;
    for (const auto& book : books) {
        if (book.getYear() > year) {
            book.display();
            cout << endl;
        }
    }
}