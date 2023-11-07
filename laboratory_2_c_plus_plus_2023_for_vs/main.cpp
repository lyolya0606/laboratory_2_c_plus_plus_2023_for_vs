#include <iostream>
#include "beginning.h"
#include "checking_errors.h"
#include "work_with_strings.h"
//#include "test.h"

using  namespace std;

enum action_with_text {
  TEXT_WORK = 1,
  TEXT_TEST
};

enum end_of_program {
  QUIT = 1,
  CONTINUE
};


int main() {
  greeting();
  int user_choice;
  bool stop;

  do {
    do {
      main_menu();
      user_choice = get_int();

      switch (user_choice) {

      case TEXT_WORK: {
        string text = "hehehe  hello mym  my nema ff";
        get_encrypted_text();
        stop = true;
        break;
      }

      case TEXT_TEST: {
        //checking_tests();
        stop = true;
        break;
      }

      default:
        cout << "There is no such choice!" << endl;
        stop = false;
      }

    } while (!stop);

    do {
      cout << endl << "Press 1 to finish" << endl;
      cout << "Press 2 to continue" << endl;
      user_choice = get_int();

      if (user_choice != QUIT && user_choice != CONTINUE) {
        cout << "There is no such choice!" << endl;
      }
    } while (user_choice != QUIT && user_choice != CONTINUE);

  } while (user_choice != QUIT);

  return 0;
}