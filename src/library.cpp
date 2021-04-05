using namespace std;
#include <iostream>
#include <fstream>
#include "library.h"
void Library::LoadBook() { // Load books.txt
    Book tmpbook;
    string str;
    ifstream fin("books.txt"); // Open and read books.txt
    if(!fin) { // If can't open
        cerr << "books.txt can't open" << endl;
        abort(); // Exit
    }
    while (getline(fin, str)) {
        size_t i = str.find("\t"); // Find tab spacebar
        // Split string by tab and get information
        tmpbook.SetName(str.substr(0, i));
        str = str.substr(i+1);

        i = str.find("\t"); // Find second spacebar
        tmpbook.SetIsbn(str.substr(0, i));
        str = str.substr(i+1);

        i = str.find("\t");
        tmpbook.SetAuthor(str.substr(0, i));
        str = str.substr(i+1);

        i = str.find("\t");
        tmpbook.SetNumber(stoi(str.substr(0, i)));
        str = str.substr(i+1);

        BookArray.push_back(tmpbook); // Add to library book array
    }
    fin.close(); // Close books.txt
}

