#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  void CutStr() {
    string str;
    int len = 0;
    cin >> str;
    cin >> len;
    for (int i = 0; i < len; i++) cout << str[i];
  }
};
int main() {
  Solution a;
  a.CutStr();
  return 0;
}
