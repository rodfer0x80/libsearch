#include <iostream>
#include <string>
#include <unistd.h>
#include <algorithm>

#include "menu.h"
#include "library.h"

#define clear() printf("\033[2J\033[1;1H");

Library lib;

// Shell greeting and load book data
void Menu::Start(){
	clear();
  std::cout << "******************************\n"
    << "******************************\n"
    << "\n<<<<<<<<< Libsearch >>>>>>>>>>\n\n"
    << "******************************\n"
    << "******************************" << std::endl;
  sleep(3);
	clear();
}

void Menu::op0(){
  lib.Backup();
  std::cout << "[EXE] Saving changes...\n";
  std::remove("books");
  std::rename("backup", "books");
  std::cout << "[EXE] Gracefully quitting...\n";
  exit(0);

}
void Menu::op1(){
  std::cout << "[EXE] Searching library...\n";
  lib.Probe();
}
void Menu::op2(){
  std::cout << "[EXE] Ready to add books...\n";
  lib.Reckon();
}
void Menu::op3(){
  std::cout << "[EXE] Ready to remove books...\n";
  lib.Abolish();
}
void Menu::op4(){
  std::cout << "[EXE] Ready to add new book...\n";
  lib.Create();
}
void Menu::opx(){
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "[ERROR] Command not found\n";
}
void Menu::op5(){
  lib.Backup();
  std::cout << "[EXE] Creating backup file...\n";
}
void Menu::op6(){
  lib.Load();
  std::cout << "[EXE] Loading data from file...\n";
}


// Menu interface
void Menu::Interface() {
    char c;
    while (1){
      std::cout << "\nLibSearch Library\n*******************\n"
        << "0) Quit program\n"
        << "1) Search book by title\n"
        << "2) Add more instances of a book to library\n"
        << "3) Remove book from library\n"
        << "4) Add new book to library\n"
        << "5) Make library backup\n"
        << "6) Load books\n";
      std::cout << ">> ";
      std::cin >> c;
      c == '0' ? op0() :
      c == '1' ? op1() :
      c == '2' ? op2() :
      c == '3' ? op3() :
      c == '4' ? op4() :
      c == '5' ? op5() :
      c == '6' ? op6() :
      opx();
      }
}

