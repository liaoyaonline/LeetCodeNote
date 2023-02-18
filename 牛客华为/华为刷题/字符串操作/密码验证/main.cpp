#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  string PasswordVerification(string str) {
    int flag[4] = {0};
    int result[4] = {1, 1, 1, 1};
    if (str.size() <= 8) {
      return "NG";
    }
    for (int i = 0; i < str.size(); i++) {
      if (str[i] >= '0' && str[i] <= '9') {
        flag[0] = 1;
      } else if (str[i] >= 'A' && str[i] <= 'Z')
        flag[1] = 1;
      else if (str[i] >= 'a' && str[i] <= 'z')
        flag[2] = 1;
      else
        flag[3] = 1;
    }
    if ((flag[0] + flag[1] + flag[2] + flag[3]) < 3) result[1] = 0;
    for (int i = 0; i < str.size() - 6; i++) {
      for (int j = i + 3; j < str.size() - 3; j++) {
        if (str.substr(i, 3) == str.substr(j, 3)) {
          result[2] = 0;
          break;
        }
      }
    }
    if (result[1] && result[2])
      return "OK";
    else
      return "NG";
  }
};
int main() {
  string str;
  Solution a;
  while (cin >> str) {
    cout << a.PasswordVerification(str) << endl;
    ;
  }
  return 0;
}
