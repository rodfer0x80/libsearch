#include <iostream>
#include <string>
#include <algorithm>
#include "book.h"
#include "library.h"
#include "utils.h"

Library lib;

void loadData() {
    lib.LoadBook(); // Load books.txt
}

void menu() { // Menu interface
    char c;
    int i;
    int flag = 0;
    std::string name;
    std::string bookname;
    //std::string tmp;
    int size = lib.BookArray.size();
    while (1){
      std::cout << "\nLibSearch Library\n*******************\n0) Quit program\n"
              << "1) Search book by title\n2) Load new books from file\n";
      std::cout << ">> ";
      std::cin >> c;
      if ( c == '0'){
        exit(0);
      } else if ( c == '1' ){
        std::cout << "Enter book title: " << std::flush;
        //std::cout << ">> " << flush;
        std::cin.ignore(1);
        std::getline(std::cin, name);
        for (i = 0; i < size; i++){
          transform(name.begin(), name.end(), name.begin(), ::tolower);
          bookname = lib.BookArray[i].GetName();
          transform(bookname.begin(), bookname.end(), bookname.begin(), ::tolower);
          if (bookname == name){
            std::cout << "\nTitle: " << lib.BookArray[i].GetName() << "\nAuthor: " <<  lib.BookArray[i].GetAuthor() << "\nISBN: " << lib.BookArray[i].GetIsbn() << "\nQuantity: " << lib.BookArray[i].GetNumber() << "\n";
          }
        }
      } else if ( c == '2' ){
        printf("Loading new books...\n");
      } else {
        printf("Command not found\n");
      }
    }
}

int main(void) {
    greeting();
    loadData(); // Load all data from book.txt
    menu(); // Menu interface
    return 0;
}
