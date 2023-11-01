#include <iostream>
#include <map>
#include <algorithm>
#include <list>

using namespace std;

void print_map(map<string, int> map_to_print) {
  map<string, int>::iterator it = map_to_print.begin();

  while (it != map_to_print.end()) {
    cout << "Key: " << it->first
      << ", Value: " << it->second << endl;
    ++it;
  }
}

void get_unused_ascii(string text) {
  list<char> all_ascii;

  for (char c{ ' ' }; c <= '~'; ++c)
    all_ascii.push_back(c + 1);

  for (char c : text) {
    if (find(all_ascii.begin(), all_ascii.end(), c) != all_ascii.end()) {
      all_ascii.remove(c);
    }
  }

  for (char item : all_ascii)
    std::cout << item << " ";

}



map<string, int> make_graph_map(string str, int size) {
  map<string, int> digraph_map;
  string key_str {""};

  for (int i = 0; i < str.length(); i+= size) {
    key_str = str.substr(i, size);
    replace(key_str.begin(), key_str.end(), ' ', '_');
    cout << key_str << endl;

    if (digraph_map.find(key_str) == digraph_map.end()) {
      digraph_map[key_str] = 1;
    } else {
      digraph_map[key_str] += 1;
    }
  }
  print_map(digraph_map);
  get_unused_ascii(str);

  return digraph_map;
}


