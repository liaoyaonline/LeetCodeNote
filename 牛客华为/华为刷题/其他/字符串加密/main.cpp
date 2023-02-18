#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  string EncryStr(string str) {
    string result;
    for (int i = 0; i < str.size(); i++) {
      string tempstr;
      if (str[i] >= 'a' && str[i] <= 'z') {
        int temnum = str[i] - 'a';
        temnum = (temnum + 1) % 26;
        tempstr = 'A' + temnum;
        result += tempstr;
      }
      if (str[i] >= 'A' && str[i] <= 'Z') {
        int temnum = str[i] - 'A';
        temnum = (temnum + 1) % 26;
        tempstr = 'a' + temnum;
        result += tempstr;
      }
      if (str[i] >= '0' && str[i] <= '9') {
        int temnum = str[i] - '0';
        temnum = (temnum + 1) % 10;
        tempstr = '0' + temnum;
        result += tempstr;
      }
    }
    return result;
  }
  string DecryStr(string str) {
    string result;
    for (int i = 0; i < str.size(); i++) {
      string tempstr;
      if (str[i] >= 'a' && str[i] <= 'z') {
        int temnum = str[i] - 'a';
        temnum = (temnum + 26 - 1) % 26;
        tempstr = 'A' + temnum;
        result += tempstr;
      }
      if (str[i] >= 'A' && str[i] <= 'Z') {
        int temnum = str[i] - 'A';
        temnum = (temnum + 26 - 1) % 26;
        tempstr = 'a' + temnum;
        result += tempstr;
      }
      if (str[i] >= '0' && str[i] <= '9') {
        int temnum = str[i] - '0';
        temnum = (temnum + 10 - 1) % 10;
        tempstr = '0' + temnum;
        result += tempstr;
      }
    }
    return result;
  }
};
int main() {
  Solution a;
  string str1;
  string str2;
  cin >> str1;
  cin >> str2;
  cout << a.EncryStr(str1) << endl;
  cout << a.DecryStr(str2) << endl;
  return 0;
}
