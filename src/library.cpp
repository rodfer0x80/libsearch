#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include "library.h"
#include <sstream>

// Load data from 'books' file
// Parse and create Book objects
// Create BookArray
// Push Book objects to BookArray
void Library::Load() {
    Book tmpbook;
    std::ifstream file("books");
    std::string line;
    std::vector<std::string> tokens;
    int i = 0;
    while(std::getline(file,line)) {
      std::istringstream iss(line);
      std::string token;
      while(std::getline(iss, token, '\t')){
        tokens.push_back(token);
      }
      tmpbook.SetName(tokens[i++]);
      tmpbook.SetAuthor(tokens[i++]);
      tmpbook.SetIsbn(tokens[i++]);
      tmpbook.SetNumber(tokens[i++]);
      BookArray.push_back(tmpbook);
    }
}

// Parse and load data from BookArray to 'dump' file
void Library::Backup() {
  int size = BookArray.size();
  int i;
  std::string filename("backup");
  std::fstream file_out;
  file_out.open(filename, std::ios_base::out);
    if (!file_out.is_open()) {
      std::cout << "[ERROR] Failed to create backup file " << filename << '\n';
    } else {
        for (i = 0; i < size; i++){
          file_out << BookArray[i].GetName() << '\t' << BookArray[i].GetAuthor() << '\t' << BookArray[i].GetIsbn() << '\t' << BookArray[i].GetNumber() << '\t' << '\n';
        }
        std::cout << "[INFO] Backup was successfully saved" << std::endl;
    }
}

// Search book by title
// In an array
// Input not case sensitive
// Return book data if match was found
void Library::Probe() {
  int size = BookArray.size();
  int i;
  int flag = 0;
  std::string bookname;
  std::string title;
  std::cout << "Enter book title >>> ";
  std::cin.ignore(1);
  std::getline(std::cin, title);
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
  int size = BookArray.size();
  int i, amount;
  int flag = 0;
  std::string title, bookname;
  std::cout << "Enter book title >>> ";
  std::cin.ignore(1);
  std::getline(std::cin, title);
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
  int size = BookArray.size();
  int i, ii, amount;
  int flag = 0;
  Book tmp;
  std::string title, bookname;
  std::cout << "Enter book title >>> ";
  std::cin.ignore(1);
  std::getline(std::cin, title);
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
        for (ii = i; ii < size; ii++){
          tmp = BookArray[ii];
          BookArray[ii] = BookArray[ii + 1];
          BookArray[ii + 1] = tmp;
        }
        BookArray.pop_back();
      }
      std::cout << "[INFO] Operation successfull" << std::endl;
    }
  }
  if (flag == 0) {
    std::cout << "[ERROR] Book title not found\n";
  }
}
