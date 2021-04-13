#include <iostream>
#include <string>
#include "book.h"
#include "library.h"

#define clear() printf("\033[2J\033[1;1H");

Library lib;


// Load data from 'books'file
// Create Book objects
// Create BookArray
void LoadData() {
    lib.Load();
}

// Shell greeting
void Greeting()
{
	clear();
  std::cout << "******************************\n"
    << "******************************\n"
    << "\n<<<<<<<<< Libsearch >>>>>>>>>>\n\n"
    << "******************************\n"
    << "******************************" << std::endl;
  sleep(3);
	clear();
}

// Menu interface
void Menu() {
    char c;
    while (1){
      std::cout << "\nLibSearch Library\n*******************\n"
        << "0) Quit program\n"
        << "1) Search book by title\n"
        << "2) Add book to library\n"
        << "3) Remove book from library\n"
        << "4) Make library backup\n";
      std::cout << ">> ";
      std::cin >> c;
      if ( c == '0'){
        printf("[EXE] Saving changes...\n");
        lib.Backup();
        std::remove("books");
        std::rename("backup", "books");
        printf("[EXE] Gracefully quitting...\n");
        exit(0);
      } else if ( c == '1' ){
        printf("[EXE] Searching library...\n");
        lib.Probe();
      } else if ( c == '2' ){
        printf("[EXE] Ready to add books...\n");
        lib.Reckon();
      } else if ( c == '3' ){
        printf("[EXE] Ready to remove books...\n");
        lib.Abolish();
      } else if ( c == '4' ){
        printf("[EXE] Creating backup file...\n");
        lib.Backup();
      } else {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        printf("[ERROR] Command not found\n");
      }
    }
}

int main(void) {
    Greeting();
    LoadData();
    Menu();
    return 0;
}
