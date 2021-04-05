#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
public:
    // Get book related information
    string GetName() { return name; }
    string GetIsbn() { return isbn; }
    string GetAuthor() { return author; }
    string GetNumber() { return number; }

    // Change book related information
    void SetName(string new_name) { name = new_name; }
    void SetIsbn(string new_isbn) { isbn = new_isbn; }
    void SetAuthor(string new_author) { author = new_author; }
    void SetNumber(string new_number) { number = new_number; }
private:
    string name;
    string isbn; // ISBN number
    string author;
    string number; // number of copies
};

#endif
