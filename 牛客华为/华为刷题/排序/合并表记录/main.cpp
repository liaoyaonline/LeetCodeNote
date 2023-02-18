#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  void AddTable() {
    int num;
    map<int, int> hashmap;
    cin >> num;
    for (int i = 0; i < num; i++) {
      int key = 0;
      int value = 0;
      cin >> key;
      cin >> value;
      hashmap[key] += value;
    }
    for (auto it = hashmap.begin(); it != hashmap.end(); it++) {
      cout << it->first << " " << it->second << endl;
    }
  }
};
int main() {
  Solution a;
  a.AddTable();
  return 0;
}
