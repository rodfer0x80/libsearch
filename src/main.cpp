#include <iostream>
#include <string>
#include <unistd.h>
#include <algorithm>
#include "book.h"
#include "library.h"
#include "menu.h"

Menu menu;

int main(void) {
    menu.Start();
    menu.Interface();
    return 0;
}
