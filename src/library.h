#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "book.h"

class Library {
public:
    void LoadBook(); // Load books.txt
    void Search(); // search algo
    void DumpBook(); // dump books to file
    std::vector<Book> BookArray; // Store all books in vector
    std::vector<std::string> NameArray;
private:
};

#endif
