#include <iostream>
#include <string>
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
          if (lib.BookArray[i].GetName() == name){
            flag = 1;
          }
        }
        if (flag == 1) {
          std::cout << "Found!\n";
        }
        flag = 0;
        std::cout << "Name of the book: " << name << std::endl;
        //std::cout << lib.BookArray[243].GetName();
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
