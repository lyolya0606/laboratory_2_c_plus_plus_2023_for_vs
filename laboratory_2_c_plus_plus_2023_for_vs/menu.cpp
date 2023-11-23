#include <iostream>

using namespace std;

void main_menu() {
  cout << endl << "Press 1 to start a program" << endl
    << "Press 2 for testing" << endl;
}

void menu_work_text() {
  cout << endl << "Press 1 to enter text from the keyboard" << endl
    << "Press 2 to enter text from the file" << endl;
  cout << "LETTERS IN THE TEXT CAN ONLY BE ENGLISH!" << endl;
}

void menu_encr_or_decr() {
  cout << endl << "Press 1 to encrypt" << endl
    << "Press 2 to decrypt" << endl;
}