#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

#include "library.h"

// Load data from 'books' file
// Parse and create Book objects
// Create BookArray
// Push Book objects to BookArray
void Library::Load(){
    Book tmpbook;
    std::string line;
    std::string filename;
    std::cout << "Enter filename >>> ";
    std::cin.ignore(1);
    std::getline(std::cin, filename);
    std::ifstream file(filename);
    Matrix<std::string> tokens;
    int i = 0;
    while(std::getline(file,line)) {
      std::istringstream iss(line);
      std::string token;
      while(std::getline(iss, token, '\t')){
        tokens.PushBack(token);
      }
      tmpbook.SetName(tokens[i++]);
      tmpbook.SetAuthor(tokens[i++]);
      tmpbook.SetIsbn(tokens[i++]);
      tmpbook.SetNumber(tokens[i++]);
      BookArray.PushBack(tmpbook);
    }
}

// Parse and load data from BookArray to 'backup' file
void Library::Backup() {
  int size = BookArray.GetSize();
  int i;
  std::string filename("backup");
  std::fstream file_out;
  // open file
  // check if is open
  // if its not open there is a problem
  file_out.open(filename, std::ios_base::out);
    if (!file_out.is_open()) {
      std::cout << "[ERROR] Failed to create backup file " << filename << '\n';
    } else {
        for (i = 0; i < size; i++){
          file_out << BookArray[i].GetName() << '\t' << BookArray[i].GetAuthor() << '\t' << BookArray[i].GetIsbn() << '\t' << BookArray[i].GetNumber() << '\t' << '\n';
        }
        std::cout << "[INFO] Backup was successfully saved" << std::endl;
        file_out.close();
    }
}

// Create new instance of book with data from user and push it to BookArray
void Library::Create(){
  Book tmpbook;
  std::string name, author, isbn, number;

  std::cout << "Enter book title >>> ";
  std::cin.ignore(1);
  std::getline(std::cin, name);
  tmpbook.SetName(name);

  std::cout << "Enter author >>> ";
  std::getline(std::cin, author);
  tmpbook.SetAuthor(author);

  std::cout << "Enter ISBN >>> ";
  std::getline(std::cin, isbn);
  tmpbook.SetIsbn(isbn);

  std::cout << "Enter quantity >>> ";
  std::getline(std::cin, number);
  tmpbook.SetNumber(number);

  BookArray.PushBack(tmpbook);
}
// Search book by title
// In an array
// Input not case sensitive
// Return book data if match was found
void Library::Probe() {
  int size = BookArray.GetSize();
  int i;
  int flag = 0;
  std::string bookname;
  std::string title;
  // get title from user
  std::cout << "Enter book title >>> ";
  std::cin.ignore(1);
  std::getline(std::cin, title);
  // find title in book array and return object data
  for (i = 0; i < size; i++){
    transform(title.begin(), title.end(), title.begin(), ::tolower);
    bookname = BookArray[i].GetName();
    transform(bookname.begin(), bookname.end(), bookname.begin(), ::tolower);
    if (bookname == title){
      flag = 1;
      std::cout << "\nID: " << i << "\nTitle: " << BookArray[i].GetName() << "\nAuthor: "
        <<  BookArray[i].GetAuthor() << "\nISBN: " << BookArray[i].GetIsbn()
        << "\nQuantity: " << BookArray[i].GetNumber() << "\n";
    }
  }
  if (flag == 0) {
    std::cout << "[ERROR] Book title not found\n";
  }
}

// Search book by title
// In an array
// Input not case sensitive
// Ask for amount to change if match
// Update number of copies of such book
// Remove book if number is 0
// Return book data if match was found
void Library::Reckon() {
  int size = BookArray.GetSize();
  int i, amount;
  int flag = 0;
  std::string title, bookname;
  // get title from user
  std::cout << "Enter book title >>> ";
  std::cin.ignore(1);
  std::getline(std::cin, title);
  // find title in book array and return object data
  // if found increment quantity by x amount from user
  for (i = 0; i < size; i++){
    transform(title.begin(), title.end(), title.begin(), ::tolower);
    bookname = BookArray[i].GetName();
    transform(bookname.begin(), bookname.end(), bookname.begin(), ::tolower);
    if (bookname == title){
      flag = 1;
      std::cout << "\nID: " << i << "\nTitle: " << BookArray[i].GetName() << "\nAuthor: "
        <<  BookArray[i].GetAuthor() << "\nISBN: " << BookArray[i].GetIsbn()
        << "\nQuantity: " << BookArray[i].GetNumber() << "\n";
      std::cout << "Enter amount of books to increment >>> ";
      std::cin >> amount;
      BookArray[i].Reckon(amount);
      std::cout << "[INFO] Operation successfull" << std::endl;
    }
  }
  if (flag == 0) {
    std::cout << "[ERROR] Book title not found\n";
  }
}


// Search book by title
// In an array
// Input not case sensitive
// Ask for amount to change if match
// Update number of copies of such book
// Return book data if match was found
void Library::Abolish() {
  int size = BookArray.GetSize();
  int i, ii, amount;
  int flag = 0;
  Book tmp;
  std::string title, bookname;
  // get title from user
  std::cout << "Enter book title >>> ";
  std::cin.ignore(1);
  std::getline(std::cin, title);
  // find title in book array and return object data
  // if found dimish quantity by x amount from user
  // feat: remove book if quantity is 0
  for (i = 0; i < size; i++){
    transform(title.begin(), title.end(), title.begin(), ::tolower);
    bookname = BookArray[i].GetName();
    transform(bookname.begin(), bookname.end(), bookname.begin(), ::tolower);
    if (bookname == title){
      flag = 1;
      std::cout << "\nID: " << i << "\nTitle: " << BookArray[i].GetName() << "\nAuthor: "
        <<  BookArray[i].GetAuthor() << "\nISBN: " << BookArray[i].GetIsbn()
        << "\nQuantity: " << BookArray[i].GetNumber() << "\n";
      std::cout << "Enter amount of books to reduce >>> ";
      std::cin >> amount;
      BookArray[i].Abolish(amount);
      if (std::stoi(BookArray[i].GetNumber()) == 0){
        BookArray.PopBack(i);
        std::cout << "[INFO] Book removed from library successfully" << std::endl;
      }
      std::cout << "[INFO] Operation successfull" << std::endl;
    }
  }
  if (flag == 0) {
    std::cout << "[ERROR] Book title not found\n";
  }
}
