#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "book.h"

class Library {
public:
    void LoadBook(); // Load books.txt
    std::vector<Book> BookArray; // Store all books in vector
    std::vector<std::string> NameArray;
private:
};

#endif
