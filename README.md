# libsearch #

### Inventory stock manager with sales reporting ###

### Build ###
* make

### Test - using Catch2 (https://github.com/catchorg/Catch2)
* make tests
#### Tests require curl and cp commands or manually taking care of dependencies (check tests/dependencies_manager.sh)

A library manager software with a TUI interface that allows for some business logic to be executed by the user along with reading and writing data to the disk.
For the design we have a main application done in a mixed  procedural  programming and OOP that serves the frontend interface interacting with the user and not validating input inside the menu  file, menu.hpp. This data is passed to the domain functions that can be found inside library.hpp and perform the business logic and keeping track of data in memory, saved to disk when the program quits.
A dynamic vector template was the data structure chosen as we can quickly access product data with good performance when we pair the key product id with a structure that holds all the data we need while getting rid of deleted books. 
For program flow we execute one of the following business actions - by title, add a new book, reduce book amount and delete it when amount is zeroed, increment amount, and search book returning data to user.  These functions have the performance of O(n) and an improved space complexity compared to a normal vector as we shrink the vector when delete a book in memory.
Testing  domain functions was done using Catch2 (stable v2) framework where we tested for basic business logic with arbitrary data, loaded and backed up data between memory and disk.
