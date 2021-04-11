#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "book.h"

class Library {
public:
    void Load(); // Load books.txt
    void Probe(); // search algo
    void Reckon(); // search algo + add books
    void Abolish(); // search algo + remove books
    void Backup(); // dump books to file
    std::vector<Book> BookArray; // Store all books in vector
    std::vector<std::string> NameArray;
private:
};

#endif
