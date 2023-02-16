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
  int minWindow(vector<int>& nums) {
    vector<int> dp(nums.size() + 1, 0);
    dp[1] = nums[0];
    int maxnum = nums[0];
    vector<int> num(nums.size() + 1, 0);
    for (int i = 1; i < num.size(); i++) num[i] = nums[i - 1];
    for (int i = 2; i < num.size(); i++) {
      dp[i] = max(dp[i - 1] + num[i], num[i]);
      maxnum = max(maxnum, dp[i]);
    }
    return maxnum;
  }
};
int main() {
  Solution a;
  vector<int> test{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  cout << a.minWindow(test) << endl;
  return 0;
}
