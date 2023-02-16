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
  int minWindow(string s) {
    int maxlen = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] >= 'a' && s[i] <= 'z') continue;
      for (int k = 1; i + k < s.size(); k++) {
        if (s[i + k] < s[i + k - 1] || s[i + k] < '0' || s[i + k] > '9') {
          maxlen = max(maxlen, k);
          break;
        }
      }
    }
    return maxlen;
  }
};
int main() {
  Solution a;
  string test;
  cin >> test;
  cout << a.minWindow(test) << endl;
  return 0;
}
