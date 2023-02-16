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
  int minWindow(vector<int> nums) {
    vector<int> dp;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != 0) dp.push_back(i);
    }
    int maxlen = 1;
    if (dp[0] != 0) maxlen = max(maxlen, dp[0] - 0);
    if (dp[dp.size() - 1] != nums.size() - 1) {
      int templen = nums.size() - 1 - dp[dp.size() - 1];
      maxlen = max(maxlen, templen);
    }
    for (int i = 1; i < dp.size(); i++) {
      int currlen = (dp[i] - dp[i - 1]) / 2;
      maxlen = max(maxlen, currlen);
    }
    return maxlen;
  }
};
int main() {
  Solution a;
  string teststr;
  vector<int> test;
  cin >> teststr;
  string tempstr = "";
  for (int i = 0; i < teststr.size(); i++) {
    if (teststr[i] == ',') {
      int tempnum = atoi(tempstr.c_str());
      test.push_back(tempnum);
      tempstr = "";
      continue;
    }
    tempstr.push_back(teststr[i]);
  }
  int tempnum2 = atoi(tempstr.c_str());
  test.push_back(tempnum2);
  cout << a.minWindow(test) << endl;
  return 0;
}
