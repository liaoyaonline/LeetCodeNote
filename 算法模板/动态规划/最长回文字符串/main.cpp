/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin() bool cmp(const word &num1, const word &num2) {
  return num1.value != num2.value ? num1.value > num2.value: num1.name <
 num2.name;} v.insert(v.begin()+3,1);map.containsKey(num) s.substr(i,2)####
 */
#include <limits.h>

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
  string minWindow(string s) {
    int maxlen = 0;
    int len = s.size();
    string res = "";
    for (int i = 0; i < s.size(); i++) {
      for (int j = 0; i + j < len && i - j >= 0; j++) {
        if (s[i + j] != s[i - j]) {
          break;
        } else if (2 * j + 1 > maxlen) {
          maxlen = 2 * j + 1;
          res = s.substr(i - j, maxlen);
        }
      }
    }
    for (int i = 1; i < s.size(); i++) {
      if (s[i] == s[i - 1]) {
        for (int j = 0; i + j < len && i - 1 - j >= 0; j++) {
          if (s[i + j] != s[i - 1 - j]) {
            break;
          } else if (2 * j + 2 >= maxlen) {
            maxlen = 2 * j + 2;
            res = s.substr(i - 1 - j, maxlen);
          }
        }
      }
    }
    return res;
  }
};
int main() {
  Solution a;
  string test = "aacabdkacaa";
  cout << a.minWindow(test) << endl;
  return 0;
}
