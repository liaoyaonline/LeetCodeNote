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
    int onums = 0;
    int minlen = 1;
    int len = 0;
    int frontlen = 0;
    int firstindex = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'o') {
        onums++;
        firstindex = i + 1;
        continue;
      }
      frontlen++;
    }
    for (int i = firstindex; i < s.size(); i++) {
      if (s[i] == 'o') {
        int currminlen = min(len, frontlen) + 1;
        minlen = min(currminlen, minlen);
        onums++;
        frontlen = len;
        len = 0;
        continue;
      }
      len++;
    }
    int currminlen = min(len, frontlen) + 1;
    minlen = min(currminlen, minlen);
    return onums % 2 != 0 ? s.size() - minlen : s.size();
  }
};
int main() {
  Solution a;
  string test;
  cin >> test;
  cout << a.minWindow(test) << endl;
  return 0;
}
