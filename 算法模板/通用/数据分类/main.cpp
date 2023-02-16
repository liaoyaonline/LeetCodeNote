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
  vector<int> split(string s, char ch) {
    vector<int> res;
    if (s.empty()) return res;
    string tempstr = "";
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ch) {
        int tempnum = atoi(tempstr.c_str());
        res.push_back(tempnum);
        tempstr = "";
        continue;
      }
      tempstr.push_back(s[i]);
    }
    int tempnum2 = atoi(tempstr.c_str());
    res.push_back(tempnum2);
    return res;
  }
  int minWindow(vector<int> nums, int mod, int check) {
    int a = 0x000000ff;
    int b = 0x0000ff00;
    int c = 0x00ff0000;
    int d = 0xff000000;
    vector<int> result(check, 0);
    for (int i = 0; i < nums.size(); i++) {
      int tempa = nums[i] & a;
      int tempb = (nums[i] & b) >> 8;
      int tempc = (nums[i] & c) >> 16;
      int tempd = (nums[i] & d) >> 24;
      int tempsum = (tempa + tempb + tempc + tempd) % mod;
      if (tempsum < check) result[tempsum]++;
    }
    int maxnum;
    for (int i = 0; i < result.size(); i++) {
      maxnum = max(maxnum, result[i]);
    }
    return maxnum;
  }
};
int main() {
  Solution a;
  vector<int> test{256, 257, 258, 259, 260, 261, 262, 263, 264, 265};
  int b = 4;
  int c = 3;
  cout << a.minWindow(test, b, c) << endl;
  return 0;
}
