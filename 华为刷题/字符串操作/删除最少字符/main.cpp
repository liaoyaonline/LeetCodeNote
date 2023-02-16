#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  string DelMinChar(string str) {
    int a[26] = {0};
    int minchar = 20;
    string result;
    for (int i = 0; i < str.size(); i++) {
      int temp = str[i] - 'a';
      a[temp]++;
    }
    for (int i = 0; i < 26; i++) {
      if (a[i] != 0 && a[i] < minchar) minchar = a[i];
    }
    for (int i = 0; i < str.size(); i++) {
      int temp = str[i] - 'a';
      if (a[temp] == minchar) continue;
      result.push_back(str[i]);
    }
    return result;
  }
};
int main() {
  string str;
  Solution a;
  cin >> str;
  cout << a.DelMinChar(str) << endl;
  return 0;
}
