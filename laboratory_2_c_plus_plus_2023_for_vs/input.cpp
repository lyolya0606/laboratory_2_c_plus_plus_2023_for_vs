#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "checking_errors.h"
#include <iomanip>

using namespace std;

ifstream open_file_input();

string file_input() {
  string text{ "" };
  string str;
  ifstream file;

  file = open_file_input();

  while (!file.eof()) {
    getline(file, str);
    text += str;
  }

  while (!are_good_symbols(text)) {
    cout << endl << "File has bad symbols. Please, try again." << endl;
    file = open_file_input();
    while (!file.eof()) {
      getline(file, str);
      text += str;
    }
  }
  cout << "Read data:" << endl << text << endl;
  file.close();
  return text;
}


string keyboard_input() {
  cout << endl << "Write the text:" << endl;
  string text{ "" };
  getline(cin, text, '\n');

  while (!are_good_symbols(text)) {
    cout << "You entered bad symbols. Please, try again." << endl;
    cout << endl << "Write the text:" << endl;
    getline(cin, text, '\n');
  }

  return text;
}

map<string, char> file_input_table() {
  string str;
  ifstream file;
  bool flag;
  map<string, char> table;

  do {
    table.clear();
    flag = true;
    file = open_file_input();

    while (true) {
      getline(file, str);
      if (str == "") {
        break;
      }
      try {
        string delimiter = "-";
        auto pos = str.find(delimiter);
        if (pos == string::npos) {
          cout << endl << "Misrepresentation of data! Please, check the file. Table should look like: symbols-meaning." << endl;
          flag = false;
          break;
        }
        string symbols = str.substr(0, pos);
        char meaning = str.substr(pos + 1, 1)[0];
        table[symbols] = meaning;
        if ((!are_good_symbols(symbols)) || (!is_letter(meaning))) {
          cout << endl << "File has bad symbols. Please, try again." << endl;
          flag = false;
        }
      } catch (exception) {
        cout << endl  << "Misrepresentation of data! Please, check the file. Table should look like: symbols-meaning." << endl;
        flag = false;
      }
    }
  } while (!flag);

  file.close();
  cout << endl << "Table for decryprion:" << endl;
  cout << "Read data:" << endl;
  cout  << "Symbols" << setw(10) << "Meaning" << endl;
  auto it = table.begin();

  while (it != table.end()) {
    cout << setw(3) << it->first << setw(10) << it->second << endl;
    ++it;
  }

  return table;
}

