#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  void ReverseStr(void) {
    string str;
    getline(cin, str);
    for (int i = str.size() - 1; i >= 0; i--) cout << str[i];
  }
};
int main() {
  Solution a;
  a.ReverseStr();
  return 0;
}
