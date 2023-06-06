#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "library.h"

using namespace std;

int main() {

    Library library("books.txt", "log.txt");

    Book book1(1, "Title1", "Author1", "Publisher1", 2020, 200, 9.99, "Hardcover");
    Book book2(2, "Title2", "Author2", "Publisher2", 2021, 250, 12.99, "Paperback");
    Book book3(3, "Title3", "Author1", "Publisher3", 2019, 180, 7.99, "Hardcover");
    Book book4(4, "Title4", "Author3", "Publisher1", 2003, 300, 20.99, "Hardcover");

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);
    library.addBook(book4);

    library.saveToFile();

    //Виведення списку книг після зчитування з файлу
    //cout << "Books after loading from file:" << endl;
    //library.displayBooks();

    library.displayBooksByAuthor("Author1");
    library.displayBooksByPublisher("Publisher1");
    library.displayBooksPublishedAfter(2005);

    return 0;
}

