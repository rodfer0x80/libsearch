#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "library.h"
#include <sstream>
void Library::LoadBook() { // Load books.txt
    Book tmpbook;
    std::ifstream file("books");
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

