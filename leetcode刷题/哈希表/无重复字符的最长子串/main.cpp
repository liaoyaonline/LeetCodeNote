/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin() bool cmp(const word &num1, const word &num2) {
  return num1.value != num2.value ? num1.value > num2.value: num1.name <
 num2.name;} v.insert(v.begin()+3,1);map.containsKey(num) s.substr(i,2)####
 */
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
    vector<int> nums(128, 0);
    int maxlen = 0;
    for (int i = 0, j = 0; j < s.size(); j++) {
      int tempnum = (int)s[j];
      nums[tempnum]++;
      if (nums[tempnum] == 1) {
        maxlen = max(maxlen, j - i + 1);
        continue;
      }
      while (nums[tempnum] > 1) {
        int tempindex = (int)s[i];
        nums[tempindex]--;
        i++;
      }
    }
    return maxlen;
  }
};
int main() {
  Solution a;
  string test = "pwwkew";
  cout << a.minWindow(test) << endl;
  return 0;
}
