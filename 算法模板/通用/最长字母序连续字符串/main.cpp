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
    int maxlen = 1;
    for (int r = 1, l = 0; r < s.size(); r++) {
      if (s[r] > s[r - 1] && s[r] - s[r - 1] == 1) {
        maxlen = max(maxlen, r - l + 1);
        continue;
      } else {
        l = r;
      }
    }
    return maxlen;
  }
};
int main() {
  Solution a;
  string test = "abcde";
  cout << a.minWindow(test) << endl;
  return 0;
}
