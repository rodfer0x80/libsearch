#include <iostream>
#include <unistd.h>
#include <algorithm>

#include "menu.h"
#include "library.hpp"

#define clear() printf("\033[2J\033[1;1H");

// user input is not validated in this program

// Shell greeting and load book data
void Menu::Start(){
	clear();
  load();
  std::cout << "******************************\n"
    << "******************************\n"
    << "\n<<<<<<<<< Libsearch >>>>>>>>>>\n\n"
    << "******************************\n"
    << "******************************" << std::endl;
  sleep(1);
	clear();
}

int Menu::op0(){
  backup();
  std::cout << "[*] Saving changes...\n";
  std::remove("books");
  std::rename("backup", "books");
  std::cout << "[*] Gracefully quitting...\n";
  exit(0);
  return 0;
}
int Menu::op1(){
  std::string title;
  std::cout << "Title >>> ";
  std::cin.ignore(1);
  std::getline(std::cin, title);

  std::string buffer = probe(title);
  std::cout << buffer;
  backup();
  return 0;
}
int Menu::op2(){
  std::string title;
  std::string amount_str;
  int amount;
  std::cout << "Title >>> ";
  std::cin.ignore(1);
  std::getline(std::cin, title);
  std::cout << "Amount >>> ";
  std::cin >> amount_str;
  amount = std::stoi(amount_str);

  int v = reckon(title, amount);
  if (v == 0){
    std::cout << "[*] Successfully reckoned book amount\n";
    
  } else {
    std::cout << "[x] Error reckoning book amount\n";
  } 
  backup();
  return 0;
}
int Menu::op3(){
  std::string title;
  std::string amount_str;
  int amount;
  std::cout << "Title >>> ";
  std::cin.ignore(1);
  std::getline(std::cin, title);
  std::cout << "Amount >>> ";
  std::cin >> amount_str;
  amount = std::stoi(amount_str);

  int v = abolish(title, amount);
  if (v == 0){
    std::cout << "[*] Successfully abolishing book\n";
    
  } else {
    std::cout << "[x] Error abolishing book\n";
  } 
  backup();
  return 0;
}
int Menu::op4(){
  std::string title, author, isbn, number;
  std::cout << "Title >>> ";
  std::cin.ignore(1);
  std::getline(std::cin, title);
  std::cout << "Author >>> ";
  std::cin.ignore(1);
  std::getline(std::cin, author);
  std::cout << "ISBN >>> ";
  std::cin.ignore(1);
  std::getline(std::cin, isbn);
  std::cout << "Number >>> ";
  std::cin.ignore(1);
  std::getline(std::cin, number);
  
  int v = create(title, author, isbn, number);

  if (v == 0){
    std::cout << "[*] Successfully created book data\n";
    
  } else {
    std::cout << "[x] Error creating book data";
  } 
  backup();
  return 0;
}
int Menu::opx(){
  //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "[x] Command not found\n";
  return 0;
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
      opx();
      }
}

