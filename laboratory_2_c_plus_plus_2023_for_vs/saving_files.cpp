#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include "checking_errors.h"
#include "file_errors.h"
#include "saving_files.h"

using namespace std;


void saving_files_input(string text, string type) {
    cout << endl << "Press 1 if you want to save your " << type << " in the file" << endl
        << "Press 2 if you DON'T want to save your " << type << " in the file" << endl;
    int choice = get_int();
    const int SAVING{ 1 };
    const int NOT_SAVING{ 2 };

    while (choice != SAVING && choice != NOT_SAVING) {
        cout << "There is no such choice!" << endl << endl
            << "Press 1 if you want to save your " << type << " in the file" << endl
            << "Press 2 if you DON'T want to save your " << type << " in the file" << endl;

        choice = get_int();
    }

    if (choice == SAVING) {
        ofstream file = open_file_output();
        file << text;

        file.close();
        cout << "The data was successfully saved" << endl;
    }
}


void saving_files_table(map<string, char> table) {
    cout << endl << "Press 1 if you want to save your the table in the file" << endl
        << "Press 2 if you DON'T want to save your the table in the file" << endl;
    int choice = get_int();
    const int SAVING{ 1 };
    const int NOT_SAVING{ 2 };

    while (choice != SAVING && choice != NOT_SAVING) {
        cout << "There is no such choice!" << endl << endl
            << "Press 1 if you want to save your the table in the file" << endl
            << "Press 2 if you DON'T want to save your the table in the file" << endl;

        choice = get_int();
    }

    if (choice == SAVING) {
        ofstream file = open_file_output();
        auto it = table.begin();

        while (it != table.end()) {
            file << it->first << "-" << it->second << endl;
            ++it;
        }

        file.close();
        cout << "The table was successfully saved" << endl;
    }
}