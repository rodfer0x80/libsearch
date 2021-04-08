#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include "library.h"
#include <sstream>
void Library::LoadBook() { // Load books.txt
    Book tmpbook;
    std::ifstream file("data/books");
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
  //std::string name;
  std::string filename("data/dump");
  std::fstream file_out;
  file_out.open(filename, std::ios_base::out);
    if (!file_out.is_open()) {
      std::cout << "Failed to open dump file " << filename << '\n';
    } else {
        for (i = 0; i < size; i++){
          file_out << BookArray[i].GetName() << '\t' << BookArray[i].GetAuthor() << '\t' << BookArray[i].GetIsbn() << '\t' << BookArray[i].GetNumber() << '\t' << '\n';
        }
        std::cout << "Dump successfully finished!" << std::endl;
    }
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
