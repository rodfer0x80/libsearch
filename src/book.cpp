#include "book.h"

Book::Book(std::string title, std::string author, double ISBN, int quantity)
{
    this->title = title;
    this->author = author;
    this->ISBN = ISBN;
    this->quantity = quantity;
}

Book::~Book(){

}

void Book::add_book(double ISBN, int amount)
{
    this->quantity += amount;
}

void Book::remove_book(double ISBN, int amount)
{
    this->quantity -= amount;
    if (this->quantity == 0) {
        this->~Book();
    }
}
