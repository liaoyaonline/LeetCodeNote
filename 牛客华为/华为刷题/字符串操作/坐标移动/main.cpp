#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  bool IsNum(string str) {
    for (int i = 0; i < str.size(); i++) {
      if (str[i] < '0' || str[i] > '9') return false;
    }
    return true;
  }
  void CoordinateMove() {
    vector<string> strchild;
    int Num[2] = {0};
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
      string temp;
      while (s[i] != ';') {
        temp.push_back(s[i]);
        i++;
      }
      strchild.push_back(temp);
    }
    for (int i = 0; i < strchild.size(); i++) {
      string str = strchild[i];
      if (str.empty()) continue;
      string s1 = str.substr(1);
      if (IsNum(s1)) {
        switch (str[0]) {
          case 'A':
            Num[0] -= stoi(s1);
            break;
          case 'D':
            Num[0] += stoi(s1);
            break;
          case 'W':
            Num[1] += stoi(s1);
            break;
          case 'S':
            Num[1] -= stoi(s1);
            break;
          default:
            break;
        }
      }
    }
    cout << Num[0] << "," << Num[1];
  }
};
int main() {
  Solution a;
  a.CoordinateMove();
  return 0;
}
