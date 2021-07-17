#ifndef MENU_H
#define MENU_H


class Menu {
public:
  void Interface(); // Menu interface
  void Start(); // Shell greeting and load book data from 'books' file
  // options for the menu
private:
  int op0();
  int op1();
  int op2();
  int op3();
  int op4();
  int opx();
};

#endif
