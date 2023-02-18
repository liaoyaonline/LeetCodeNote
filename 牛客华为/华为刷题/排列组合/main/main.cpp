#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  int BracketsLen(string s) {
    int maxdeep = 0;
    int tempdeep = 0;
    for (int i = 0; i < s.size(); i++) {
      switch (s[i]) {
        case '(':
          tempdeep++;
          maxdeep = max(maxdeep, tempdeep);
          break;
        case ')':
          tempdeep--;
          break;
      }
    }
    return maxdeep;
  }
};
int main() {
  Solution a;
  string str;
  cin >> str;
  cout << a.BracketsLen(str) << endl;
  return 0;
}
