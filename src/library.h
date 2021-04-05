#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "book.h"
using namespace std;

class Library {
public:
    void LoadBook(); // Load books.txt
    vector<Book> BookArray; // Store all books in vector
private:
};

#endif
