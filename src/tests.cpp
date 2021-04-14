// wubba lubba dub dub
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include "book.h"
#include "library.h"
#define clear() printf("\033[2J\033[1;1H");

Library lib;
// number of test to pass vs total
int F;
int T = 4;
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

// check if opened file is empty
bool is_empty(std::ifstream& bFile)
{
    return bFile.peek() == std::ifstream::traits_type::eof();
}

// simulation of lib.Probe function
void test_probe(){
  std::cout << "[TEST] 2) Probe algorithm + Book Class functions";
  int size = lib.BookArray.GetSize();
  int i;
  int flag = 0;
  std::string bookname;
  std::string title = "x marks the spot";
  for (i = 0; i < size; i++){
    transform(title.begin(), title.end(), title.begin(), ::tolower);
    bookname = lib.BookArray[i].GetName();
    transform(bookname.begin(), bookname.end(), bookname.begin(), ::tolower);
    if (bookname == title){
      flag = 1;
      std:: cout << " - PASSED\n";
      F++;
    }
  }
  if (flag == 0) {
    std::cout << " - FAILED\n";
  }
}

void test_backup()
{
  lib.Backup();
  std::cout << "[TEST] 1) Backup file ";
  std::ifstream bFile("backup");

  if (!bFile){
    std::cout << " - FAILED\n";
  } else if (is_empty(bFile)){
    std::cout << " - FAILED\n";
  } else {
    F++;
    std::cout << " - PASSED\n";
    std::remove("backup");
  }
}

// simulation of lib.Reckon function
void test_reckon(){
  std::cout << "[TEST] 3) Reckon algorithm + Book Class functions";
  int size = lib.BookArray.GetSize();
  int i;
  int flag = 0;
  std::string bookname;
  std::string title = "suckLESS software";
  for (i = 0; i < size; i++){
    transform(title.begin(), title.end(), title.begin(), ::tolower);
    bookname = lib.BookArray[i].GetName();
    transform(bookname.begin(), bookname.end(), bookname.begin(), ::tolower);
    if (bookname == title){
      lib.BookArray[i].Reckon(10);
      if (lib.BookArray[i].GetNumber() == "20")
        F++;
        flag = 1;
        std:: cout << " - PASSED\n";
    }
  }
  if (flag == 0) {
    std::cout << " - FAILED\n";
  }
}

// simulation of lib.Abolish functionb
void test_abolish(){
  std::cout << "[TEST] 4) Abolish algorithm + Book Class functions";
  int size = lib.BookArray.GetSize();
  int i;
  int flag = 0;
  std::string bookname;
  std::string title = "adobe reader is literally";
  for (i = 0; i < size; i++){
    transform(title.begin(), title.end(), title.begin(), ::tolower);
    bookname = lib.BookArray[i].GetName();
    transform(bookname.begin(), bookname.end(), bookname.begin(), ::tolower);
    if (bookname == title){
      lib.BookArray[i].Abolish(1);
    }
  }
  for (i = 0; i < size; i++){
    if (bookname == title){
      flag = 1;
      std::cout << " - FAILED\n";
    }
  }
  if (flag == 0){
    F++;
    std::cout << " - PASSED\n";
  }
}

// Test function
void Test()
{
  Book tmpbook;

  tmpbook.SetName("Adobe Reader is literally");
  tmpbook.SetAuthor("sane guy no1");
  tmpbook.SetIsbn("8080");
  tmpbook.SetNumber("1");
  lib.BookArray.PushBack(tmpbook);

  tmpbook.SetName("X marks the spot");
  tmpbook.SetAuthor("random pirate no13");
  tmpbook.SetIsbn("13");
  tmpbook.SetNumber("7");
  lib.BookArray.PushBack(tmpbook);

  tmpbook.SetName("suckless software");
  tmpbook.SetAuthor("suckless devs");
  tmpbook.SetIsbn("666");
  tmpbook.SetNumber("10");
  lib.BookArray.PushBack(tmpbook);
  test_backup();
  test_probe();
  test_reckon();
  test_abolish();
  std::cout << "[INFO] Passed " << F << "/" << T << " tests." << std::endl;
  if (F == 4)
    std::cout << "[INFO] Hurray! All test succesfully passed!" << std::endl;
}

int main(void) {
    Greeting();
    LoadData();
    Test();
    return 0;
}
