#include <iostream>
#include <map>
#include <windows.h>
#include <algorithm>
#include <list>
#include <vector>
#include "work_with_strings.h"
#include <iomanip>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include "beginning.h"
#include "checking_errors.h"
#include "input.h"
#include "saving_files.h"

using namespace std;

enum input_choice {
  DIGRAPH = 2,
  TRIGRAPH
};

enum size_of_graph {
  KEYBOARD_INPUT = 1,
  FILE_INPUT
};

enum encrypt_decrypt {
  ENCRYPT = 1,
  DECRYPT
};

vector<char> get_unused_ascii(string text) {
  vector<char> all_ascii;
  for (char c{ ' ' }; c <= '~'; ++c) {
    all_ascii.push_back(c);
  }

  /*for (char c{ 'À' }; c <= 'ÿ'; ++c) {
    all_ascii.push_back(c);
  }*/


  for (char c : text) {
    if (find(all_ascii.begin(), all_ascii.end(), c) != all_ascii.end()) {
      auto it = find(all_ascii.begin(), all_ascii.end(), c);
      all_ascii.erase(it);
    }
  }
  return all_ascii;

}

map<string, char> make_table_for_encryption(map<string, int> map_for_encryption, string text) {
  map<string, char> table;
  vector<char> all_ascii = get_unused_ascii(text);

  vector<int> list_for_rand;
  for (int i = 0; i < all_ascii.size(); i++) {
    list_for_rand.push_back(i);
  }

  int index{ -1 };


  auto it = map_for_encryption.begin();
  while (it != map_for_encryption.end()) {
    srand((unsigned int)time(nullptr));
    index = rand() % list_for_rand.size();
    table[it->first] = all_ascii[list_for_rand[index]];
    list_for_rand.erase(list_for_rand.begin() + index);
    ++it;
  }

  return table;
}


void print_map(map<string, int> map_to_print) {
	auto it = map_to_print.begin();

  while (it != map_to_print.end()) {
    cout << "Key: " << it->first
      << ", Value: " << it->second << endl;
    ++it;
  }
}

string work_with_input() {
  int user_choice;
  bool stop;
  string text{};
  do {
    menu_work_text();
    user_choice = get_int();

    switch (user_choice) {

    case KEYBOARD_INPUT: {
      text = keyboard_input();
      saving_files_input(text, "input");
      //saving_files_input(text, "input");
      stop = true;
    }
    break;

    case FILE_INPUT: {
      text = file_input();
      stop = true;
    }
    break;

    default:
      cout << "There is no such choice!" << endl;
      stop = false;
    }

  } while (!stop);
  return text;
}


map<string, int> make_graph_map(string str, int size) {
  map<string, int> graph_map;
  string key_str {""};

  for (int i = 0; i < str.length(); i+= size) {
    key_str = str.substr(i, size);
    replace(key_str.begin(), key_str.end(), ' ', '_');
   // cout << key_str << endl;

    if (graph_map.find(key_str) == graph_map.end()) {
      graph_map[key_str] = 1;
    } else {
      graph_map[key_str] += 1;
    }
  }
  //print_map(graph_map);
 // get_unused_ascii(str);

  return graph_map;
}


int encryption(string text, int size) {
    string result_text{ "" };
    map<string, int> graph_map = make_graph_map(text, size);
    map<string, char> table = make_table_for_encryption(graph_map, text);
    string key_str{ "" };

    for (int i = 0; i < text.length(); i += size) {
        key_str = text.substr(i, size);
        replace(key_str.begin(), key_str.end(), ' ', '_');
        result_text += table[key_str];
    }

    cout << endl << "Input text: " << endl << "\033[1;32m" << text << "\033[0m" << endl;
    cout << endl << "Result for graph with " << size << " symbols:" << endl;
    cout << "\033[1;32m" << result_text << "\033[0m" << endl << endl;
    cout << "Table for decryprion:" << endl;
    cout  << "Symbol" << setw(10) << "Meaning" << endl;
    auto it = table.begin();

    while (it != table.end()) {
        cout << setw(3) << it->first << setw(10) << it->second << endl;
        ++it;
    }

    if (size == TRIGRAPH) {
      saving_files_input(result_text, "output");
      saving_files_table(table);
    }

    return (int)(result_text.length() + table.size());
}

void decryption(string text) {
  cout << "The table for decryption must be in the file." << endl;
  map<string, char> table = file_input_table();
  string result_text{ "" };

  for (char c : text) {
    for (auto& it : table) {

      if (it.second == c) {
        result_text += it.first;
      }
    }
  }

  cout << endl << "Input text:" << endl << "\033[1;32m" << text << "\033[0m" << endl;
  cout << endl << "Result of the decryprion:" << endl;
  cout << "\033[1;32m" << result_text << "\033[0m" << endl << endl;
}

void conclusion(string text, int result_of_digraph, int result_of_trigraph) {
  double size_of_digraph = (double)result_of_digraph / (double)text.length();
  double size_of_trigraph = (double)result_of_trigraph / (double)text.length();

  cout << endl << "\033[1;34m" << "CONCLUSION" << "\033[0m" << endl;
  cout << endl;
  if (size_of_digraph > size_of_trigraph) {
    cout << "Digraph's compression ratio (" << "\033[1;31m" << setprecision(2) << size_of_digraph << "\033[0m"
      << ") is worse than trigraph's (" << "\033[1;32m"  << size_of_trigraph << "\033[0m" << ")" << endl;
  } else{
    cout << "Digraph's compression ratio (" << "\033[1;32m" << setprecision(2) << size_of_digraph << "\033[0m"
      << ") is better than trigraph's (" << "\033[1;31m" << size_of_trigraph << "\033[0m" << ")" << endl;
  }
}

void get_encrypted_text() {
  int user_choice;
  bool stop;
  string text{};

  do {
    menu_encr_or_decr();
    user_choice = get_int();

    switch (user_choice) {

    case ENCRYPT: {
      text = work_with_input();
      int result_of_digraph = encryption(text, DIGRAPH);
      int result_of_trigraph = encryption(text, TRIGRAPH);
      conclusion(text, result_of_digraph, result_of_trigraph);
      stop = true;
    }
    break;

    case DECRYPT: {
      text = work_with_input();
      decryption(text);
      stop = true;
    }
    break;

    default:
      cout << "There is no such choice!" << endl;
      stop = false;
    }

  } while (!stop);
}


string work_for_test(string text) {
  map<string, int> graph_map = make_graph_map(text, TRIGRAPH);
  map<string, char> table;
  vector<char> all_ascii = get_unused_ascii(text);

  vector<int> list_for_rand;
  for (int i = 0; i < all_ascii.size(); i++) {
    list_for_rand.push_back(i);
  }

  int index{ 0 };

  auto it = graph_map.begin();
  while (it != graph_map.end()) {

    table[it->first] = all_ascii[list_for_rand[index]];
    list_for_rand.erase(list_for_rand.begin() + index);
    ++it;
    index++;
  }

  string result_text{ "" };
  string key_str{ "" };

  for (int i = 0; i < text.length(); i += TRIGRAPH) {
    key_str = text.substr(i, TRIGRAPH);
    replace(key_str.begin(), key_str.end(), ' ', '_');
    result_text += table[key_str];
  }

  return result_text;
}

