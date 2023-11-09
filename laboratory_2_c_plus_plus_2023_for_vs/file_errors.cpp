#include "file_errors.h"
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include "checking_errors.h"

using namespace std;

ofstream open_file_output() {
  const int FILE_HAS_DATA{ 0 };
  const int OVERWRITE_FILE{ 1 };
  const int OVERWRITE_PATH{ 2 };

  bool is_path_correct;
  ofstream file;
  string path;

  do {
    int choice;
    ifstream existFile;

    cout << "Input the path to the file: ";
    getline(cin, path);
    file.open(path, ios::app);

    if (file.is_open()) {
      error_code ec;
      is_path_correct = true;


      if (!filesystem::is_regular_file(path, ec)) {
        cout << "Opening error! Try again." << endl;
        file.close();
        is_path_correct = false;
      }
      file.close();

    } else {
      cout << "Opening error! Try again." << endl;
      is_path_correct = false;
    }

    if (is_path_correct) {
      existFile.open(path);
      string line{};
      string stringGeneral{};

      while (!existFile.eof()) {
        getline(existFile, line);
        stringGeneral += line;
      }

      existFile.close();

      if (stringGeneral.length() != FILE_HAS_DATA) {
        cout << endl << "This file has some data. Do you want to overwrite the file?" << endl
          << "Press 1 if you want to overwrite this file" << endl
          << "Press 2 if you DON'T want to overwrite this file" << endl;

        choice = get_int();

        while (choice != OVERWRITE_PATH && choice != OVERWRITE_FILE) {
          cout << "There is no such choice!" << endl
            << "Press 1 if you want to overwrite this file" << endl
            << "Press 2 if you DON'T want to overwrite this file" << endl;

          choice = get_int();
        }

        if (choice == OVERWRITE_PATH) {
          is_path_correct = false;
        }

        if (choice == OVERWRITE_FILE) {
          is_path_correct = true;
        }

      }

      existFile.close();
    }

    if (!is_path_correct) {
      file.close();
    }

  } while (!is_path_correct);

  file.open(path);

  return file;
}

ifstream open_file_input() {
  //    const int FILE_HAS_DATA {0};
  //    const int OVERWRITE_PATH {1};

  bool is_path_correct;
  ifstream file;
  string path;

  do {
    cout << "Input the path to the file: ";
    getline(cin, path);
    file.open(path);

    if (file.is_open()) {
      error_code ec;
      is_path_correct = true;

      if (!filesystem::is_regular_file(path, ec)) {
        cout << "Opening error! Try again." << endl;
        file.close();
        is_path_correct = false;
      }
      file.close();

    } else {
      cout << "Opening error! Try again." << endl;
      is_path_correct = false;
    }

    if (!is_path_correct) {
      file.close();
    }

  } while (!is_path_correct);

  file.open(path);

  return file;
}