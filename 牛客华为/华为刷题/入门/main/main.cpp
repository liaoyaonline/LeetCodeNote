#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;
class Solution {
 public:
  void HexCon(void) {
    string str;
    while (cin >> str) {
      int nums = 0;
      int len = str.size();
      for (int i = (len - 1); i >= 0; i--) {
        if (str[i] >= '0' && str[i] <= '9') {
          nums += (str[i] - '0') * pow(16, (len - i - 1));
        }
        if (str[i] >= 'A' && str[i] <= 'F') {
          nums += (str[i] - 'A' + 10) * pow(16, (len - i - 1));
        }
      }
      cout << nums << endl;
    }
  }
};
int main() {
  Solution a;
  a.HexCon();
  return 0;
}
