#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  int ReverseStr(string str) {
    int a[128] = {0};
    int maxlen = 0;
    int templen = 0;
    for (int i = 0, j = 0; j < str.size(); j++) {
      a[(int)str[j]]++;
      while (a[(int)str[j]] > 1) {
        a[(int)str[i]]--;
        i++;
      }
      templen = j - i + 1;
      if (templen > maxlen) maxlen = j - i + 1;
    }
    return maxlen;
  }
};
int main() {
  Solution a;
  string str;
  cin >> str;
  cout << a.ReverseStr(str) << endl;
  return 0;
}
