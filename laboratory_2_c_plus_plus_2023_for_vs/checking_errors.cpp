#include <iostream>
#include "checking_errors.h"

using namespace std;

int get_int() {
  int input = 0;
  cin >> input;

  while (cin.fail()) {
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout << "Input Error. Enter the number." << endl;
    cin >> input;
  }

  cin.ignore(INT_MAX, '\n');
  return input;
}

bool is_letter(char symbol) {
  return ((!symbol < ' ' || symbol > '~'));
}

bool are_good_symbols(string str) {
  for (auto symbol : str) {
    if (symbol < ' ' || symbol > '~') {
      return false;
    }
  }
  return true;
}