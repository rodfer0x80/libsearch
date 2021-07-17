#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>

#include "book.hpp"
#include "matrix.hpp"

Matrix<Book> BookArray;

std::string data_file = "books";
std::string backup_file = "backup";

// Load book data from file
int load(){
    Book tmpbook;
    std::string line;

    std::ifstream file(data_file);

    Matrix<std::string> tokens;

    int i = 0;
    while(std::getline(file,line)) {
      std::istringstream iss(line);
      std::string token;
      while(std::getline(iss, token, '\t')){
        tokens.PushBack(token);
      }
      tmpbook.SetName(tokens[i++]);
      tmpbook.SetAuthor(tokens[i++]);
      tmpbook.SetIsbn(tokens[i++]);
      tmpbook.SetNumber(tokens[i++]);
      BookArray.PushBack(tmpbook);
    }
    return 0;
}

// Parse and load data from BookArray to 'backup' file
int backup() {
  int size = BookArray.GetSize();
  std::fstream file;
  file.open(backup_file, std::ios_base::out | std::ios_base::app);

    if (!file.is_open()) {
      return 1;
    } else {
        for (int i = 0; i < size; i++){
          file << BookArray[i].GetName() << '\t'
            << BookArray[i].GetAuthor()
            << '\t' << BookArray[i].GetIsbn() << '\t'
            << BookArray[i].GetNumber() << '\t' << '\n';
        }
        
    }
    file.close();
    return 0;
}

// Create new instance of book with data from user and push it to BookArray
int create(std::string title, std::string author, std::string isbn, std::string number){
  Book tmpbook;

  tmpbook.SetName(title);
  tmpbook.SetAuthor(author);
  tmpbook.SetIsbn(isbn);
  tmpbook.SetNumber(number);

  BookArray.PushBack(tmpbook);

  return 0;
}

// Search book in book array and return if exists
std::string probe(std::string title) {
  int size = BookArray.GetSize();
  std::string buffer;

  int flag = 1;
  std::string bookname;

  // find title in book array and return object data
  transform(title.begin(), title.end(), title.begin(), ::tolower);
  for (int i = 0; i < size; i++){
    bookname = BookArray[i].GetName();
    transform(bookname.begin(), bookname.end(), bookname.begin(), ::tolower);
    if (bookname == title){
      flag = 0;
      buffer = buffer + "ID: " + std::to_string(i) + "\nTitle: " + BookArray[i].GetName() + "\nAuthor: " 
        +  BookArray[i].GetAuthor() + "\nISBN: " + BookArray[i].GetIsbn()
        + "\nQuantity: " + BookArray[i].GetNumber() + "\n";
    }
  }
  if (flag == 1) {
    buffer = "Book not found";
  }
  return buffer;
}

// Search for book and increment amount by x if found
int reckon(std::string title, int amount) {
  int size = BookArray.GetSize();
  int flag = 1;
  std::string bookname;
  std::string buffer;

  for (int i = 0; i < size; i++){
    transform(title.begin(), title.end(), title.begin(), ::tolower);
    bookname = BookArray[i].GetName();
    transform(bookname.begin(), bookname.end(), bookname.begin(), ::tolower);

    if (bookname == title){
      flag = 0;
      BookArray[i].Reckon(amount);
    }
  }
  
  return flag;
}

// Search books and reduce by x amount if found, delete if stock is 0
int abolish(std::string title, int amount) {
  int size = BookArray.GetSize();
  int flag = 1;
  Book tmp;
  std::string bookname;
  std::string buffer;

  for (int i = 0; i < size; i++){
    transform(title.begin(), title.end(), title.begin(), ::tolower);
    bookname = BookArray[i].GetName();
    transform(bookname.begin(), bookname.end(), bookname.begin(), ::tolower);
    
    if (bookname == title){
      flag = 0;
      BookArray[i].Abolish(amount);
      if (std::stoi(BookArray[i].GetNumber()) == 0){
        BookArray.PopBack(i);
      }
    }
  }
  return flag;
}
