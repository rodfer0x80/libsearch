// test.cpp
// Catch2 v2.x stable branch
// Compile using C++11 for the tests
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// src files
#include "menu.hpp"
Menu menu;

// Frontend as no input validation 
// Unit testing of domain and integration (mixed) follows



TEST_CASE( "Backup book objects to file", "[backup]" ) {
    Book tmpbook;

    tmpbook.SetName("name1");
    tmpbook.SetAuthor("author1");
    tmpbook.SetIsbn("isbn1");
    tmpbook.SetNumber("1");

    BookArray.PushBack(tmpbook);
    
    int v = backup();

    REQUIRE( v == 0 );
}

TEST_CASE( "Load book data from file", "[load]" ) {
    Book tmpbook;

    int v = load();
    REQUIRE( v == 0 );

    std::string title = BookArray[0].GetName();
    std::string isbn = BookArray[0].GetIsbn();
    std::string author = BookArray[0].GetAuthor();
    std::string number = BookArray[0].GetNumber();

    REQUIRE( title == "name1" );
    REQUIRE( author == "author1" );
    REQUIRE( isbn == "isbn1");
    REQUIRE( number == "1" );
}

TEST_CASE( "Increment book amount", "[reckon]" ) {
    Book tmpbook;

    tmpbook.SetName("name2");
    tmpbook.SetAuthor("author1");
    tmpbook.SetIsbn("isbn1");
    tmpbook.SetNumber("5");

    BookArray.PushBack(tmpbook);

    int v = reckon("name2", 5);
    REQUIRE( v == 0 );
    
    std::string title = BookArray[420].GetName();
    std::string number = BookArray[420].GetNumber();

    REQUIRE( title == "name2" );
    REQUIRE( number == "10");
}

TEST_CASE( "Return book data", "[probe]" ) {
    Book tmpbook;

    std::string buffer = "ID: 0\nTitle: name1\nAuthor: author1\nISBN: isbn1\nQuantity: 1\n";

    std::string book_data = probe("name1");    

    REQUIRE( book_data == buffer );
}

TEST_CASE( "Reduce book amount and delete if amount is zeroed", "[abolish]" ) {
    Book tmpbook;

    tmpbook.SetName("name4");
    tmpbook.SetAuthor("author1");
    tmpbook.SetIsbn("isbn1");
    tmpbook.SetNumber("5");

    BookArray.PushBack(tmpbook);

    std::string title = "name4";
    int amount = 2;
    
    int v = abolish(title, amount);
    REQUIRE( v == 0 );
    
    title = BookArray[421].GetName();
    std::string number = BookArray[421].GetNumber();

    REQUIRE( title == "name4" );
    REQUIRE( number == "3" );

    SECTION( "Delete when zeroed" ){
        int amount = 2;
        v = abolish(title, amount);
        REQUIRE( v == 0 );
    
        title = BookArray[422].GetName();
        number = BookArray[422].GetNumber();

        REQUIRE( title == "" );
        REQUIRE( number == "");
    }

}

TEST_CASE( "Create new book object", "[create]" ) {
    std::string title = "title1";
    std::string isbn = "isbn1";
    std::string author = "author1";
    std::string number = "1";
    
    int v = create(title, author, isbn, number);
    REQUIRE( v == 0);

    title = BookArray[422].GetName();
    isbn = BookArray[422].GetIsbn();
    author = BookArray[422].GetAuthor();
    number = BookArray[422].GetNumber();

    REQUIRE( title == "title1" );
    REQUIRE( author == "author1" );
    REQUIRE( isbn == "isbn1");
    REQUIRE( number == "1" );
}