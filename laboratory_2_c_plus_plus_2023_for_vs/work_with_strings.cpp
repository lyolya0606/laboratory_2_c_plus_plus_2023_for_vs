#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> make_digraph_map(string str) {
  map<string, int> digraph_map;
  string key_str = "";

  for (int i = 0; i < str.length(); i+=2) {
    key_str = str.substr(i, 2);
    replace(key_str.begin(), key_str.end(), ' ', '_');
    cout << key_str << endl;

    if (digraph_map.find(key_str) == digraph_map.end()) {
      digraph_map[key_str] = 1;
    } else {
      digraph_map[key_str] += 1;
    }
  }
  print_map(digraph_map);

  return digraph_map;
}

void print_map(map<string, int> map_to_print) {
  map<string, int>::iterator it = map_to_print.begin();

  while (it != map_to_print.end()) {
    cout << "Key: " << it->first
      << ", Value: " << it->second << endl;
    ++it;
  }
}