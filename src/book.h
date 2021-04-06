#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:
    // Get book related information
  std::string GetName() { return name; }
  std::string GetIsbn() { return isbn; }
  std::string GetAuthor() { return author; }
  std::string GetNumber() { return number; }

  // Change book related information
  void SetName(std::string new_name) { name = new_name; }
  void SetIsbn(std::string new_isbn) { isbn = new_isbn; }
  void SetAuthor(std::string new_author) { author = new_author; }
  void SetNumber(std::string new_number) { number = new_number; }
private:
  std::string name;
  std::string isbn; // ISBN number
  std::string author;
  std::string number; // number of copies
};

#endif
