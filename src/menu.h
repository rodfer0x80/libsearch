#ifndef MENU_H
#define MENU_H


class Menu {
public:
  void Interface(); // Menu interface
  void Start(); // Shell greeting and load book data from 'books' file
  // options for the menu
private:
  void op0();
  void op1();
  void op2();
  void op3();
  void op4();
  void op5();
  void op6();
  void opx();
};

#endif
