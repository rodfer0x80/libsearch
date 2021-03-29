#ifndef _BOOK_H_
#define _BOOK_H_

#include <string.h>

class Book 
{
    // Class to represent books in a library system
    private:
        std::string title;
        std::string author;
        int quantity;
        double ISBN;
    public:
        Book(std::string title, std::string author, double ISBN, int quantity);
        ~Book();
        void add_book(double ISBN, int amount);
        void remove_book(double ISBN, int amount);
};

#endif
