// wubba lubba dub dub
#include <iostream>
#include <string>
#include <fstream>
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
    << "\n<<<<< Testing Framework >>>>>\n\n"
    << "******************************\n"
    << "******************************" << std::endl;
  //sleep(3);
	clear();
}

void test_backup()
{
  lib.Backup();
  std::cout << "[TEST] 1) Backup file";
  std::ifstream bFile("backup");

  if (!bFile){
    std::cout << "[TEST] 1) FAILED";
  } else if (std::is_empty(bFile)){
    std::cout << "[TEST] 1) FAILED";
  } else {
    std::cout << "[TEST] 1) PASSED";
  }
}
// Test function
void Test()
{
  test_backup();

}

int main(void) {
    Greeting();
    LoadData();
    Test();
    return 0;
}
