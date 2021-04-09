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
void Library::Dump() {
  int size = BookArray.size();
  int i;
  //std::string name;
  std::string filename("dump");
  std::fstream file_out;
  file_out.open(filename, std::ios_base::out);
    if (!file_out.is_open()) {
      std::cout << "[ERROR] Failed to open dump file " << filename << '\n';
    } else {
        for (i = 0; i < size; i++){
          file_out << BookArray[i].GetName() << '\t' << BookArray[i].GetAuthor() << '\t' << BookArray[i].GetIsbn() << '\t' << BookArray[i].GetNumber() << '\t' << '\n';
        }
        std::cout << "[SUCESS] Dump successfully saved!" << std::endl;
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
  std::string name;
  std::cout << "Enter book title: " << std::flush;
  std::cin.ignore(1);
  std::getline(std::cin, name);
  for (i = 0; i < size; i++){
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    bookname = BookArray[i].GetName();
    transform(bookname.begin(), bookname.end(), bookname.begin(), ::tolower);
    if (bookname == name){
      flag = 1;
      std::cout << "\nTitle: " << BookArray[i].GetName() << "\nAuthor: "
        <<  BookArray[i].GetAuthor() << "\nISBN: " << BookArray[i].GetIsbn()
        << "\nQuantity: " << BookArray[i].GetNumber() << "\n";
    }
  }
  if (flag == 0) {
    std::cout << "[ERROR] Book title not found\n";
  }
  flag = 0;
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
  int i;
  int amount;
  std::string bookname;
  std::string name;
  std::cout << "Enter book title: " << std::flush;
  std::cin.ignore(1);
  std::getline(std::cin, name);
  for (i = 0; i < size; i++){
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    bookname = BookArray[i].GetName();
    transform(bookname.begin(), bookname.end(), bookname.begin(), ::tolower);
    if (bookname == name){
      std::cout << "Enter amount of books to increment: ";
      std::cin >> amount;
      BookArray[i].Reckon(amount);
      std::cout << "[INFO] Operation successfull!" << std::endl;
      std::cout << "\nTitle: " << BookArray[i].GetName() << "\nAuthor: "
        <<  BookArray[i].GetAuthor() << "\nISBN: " << BookArray[i].GetIsbn()
        << "\nQuantity: " << BookArray[i].GetNumber() << "\n";
    }
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
  int i;
  int amount;
  std::string bookname;
  std::string name;
  std::cout << "Enter book title: " << std::flush;
  std::cin.ignore(1);
  std::getline(std::cin, name);
  for (i = 0; i < size; i++){
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    bookname = BookArray[i].GetName();
    transform(bookname.begin(), bookname.end(), bookname.begin(), ::tolower);
    if (bookname == name){
      std::cout << "Enter amount of books to reduce: ";
      std::cin >> amount;
      BookArray[i].Abolish(amount);
      std::cout << "[INFO] Operation successfull!" << std::endl;
      std::cout << "\nTitle: " << BookArray[i].GetName() << "\nAuthor: "
        <<  BookArray[i].GetAuthor() << "\nISBN: " << BookArray[i].GetIsbn()
        << "\nQuantity: " << BookArray[i].GetNumber() << "\n";
    }
  }
}
