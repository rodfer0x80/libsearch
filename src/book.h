#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:
  std::string GetName() { return name; }
  std::string GetIsbn() { return isbn; }
  std::string GetAuthor() { return author; }
  std::string GetNumber() { return number; }

  // Get book related information
  void SetName(std::string new_name) { name = new_name; }
  void SetIsbn(std::string new_isbn) { isbn = new_isbn; }
  void SetAuthor(std::string new_author) { author = new_author; }
  void SetNumber(std::string new_number) { number = new_number; }

  // Manage book storage
  void Reckon(int amount) {
    int n;
    n = std::stoi(number);
    n = n + amount;
    number = std::to_string(n);
  }
  void Abolish(int amount) {
    int n;
    n = std::stoi(number);
    n = n - amount;
    number = std::to_string(n);
  }

private:
  std::string name;
  std::string isbn; // ISBN number
  std::string author;
  std::string number; // number of copies
};

#endif
