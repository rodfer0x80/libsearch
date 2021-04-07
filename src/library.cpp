#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include "library.h"
#include <sstream>
void Library::LoadBook() { // Load books.txt
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

void Library::DumpBook() { //dump books to dump.txt
  int size = BookArray.size();
  int i;
  std::string name;
  //for (i = 0; i < size; i++){
    //BookArray.
  //}
}

void Library::Search() {
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
    std::cout << "Book title not found\n";
  }
  flag = 0;
}
