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
    //std::string tmp;
    while (1){
      std::cout << "\nLibSearch Library\n*******************\n0) Quit program\n"
              << "1) Search book by title\n2) Load new books from file\n";
      std::cout << ">> ";
      std::cin >> c;
      if ( c == '0'){
        exit(0);
      } else if ( c == '1' ){
        lib.Search();
      } else if ( c == '2' ){
        printf("Loading new books...\n");
        lib.DumpBook();
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
