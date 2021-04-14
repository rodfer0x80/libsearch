#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "book.h"
#include "matrix.h"

class Library {
public:
    void Load(); // Load books.txt
    void Create(); // Create new book object with terminal interface
    void Probe(); // search algo
    void Reckon(); // search algo + add books
    void Abolish(); // search algo + remove books
    void Backup(); // dump books to file
    Matrix<Book> BookArray; // Store all books in vector
private:
};

#endif
