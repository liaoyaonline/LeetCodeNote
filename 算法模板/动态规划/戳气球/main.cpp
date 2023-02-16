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
    vector<vector<int>> dp(nums.size() + 2, vector<int>(nums.size() + 2, 0));
    vector<int> v(nums.size() + 2, 1);
    for (int i = 0; i < nums.size(); i++) {
      v[i + 1] = nums[i];
    }
    for (int j = 0; j < v.size(); j++) {
      for (int i = j; i >= 0; i--) {
        if (i >= j - 1) continue;
        int maxnum = 0;
        for (int k = i + 1; k < j; k++) {
          int tempnum = dp[i][k] + (v[i] * v[k] * v[j]) + dp[k][j];
          maxnum = max(maxnum, tempnum);
        }
        dp[i][j] = maxnum;
      }
    }
    return dp[0][nums.size() + 1];
  }
};
int main() {
  Solution a;
  vector<int> test{1, 5};
  cout << a.minWindow(test) << endl;
  return 0;
}
