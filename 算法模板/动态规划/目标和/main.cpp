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
  int minWindow(vector<int>& nums, int target) {
    int m = 0;
    for (int i = 0; i < nums.size(); i++) m += nums[i];
    if (m < abs(target) || (m + target) % 2 != 0) return 0;
    m = (m + target) / 2;
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        if (j >= nums[i - 1])
          dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
        else
          dp[i][j] = dp[i - 1][j];
      }
    }
    return dp[n][m];
  }
};
int main() {
  Solution a;
  vector<int> test{1, 1, 1, 1, 1};
  cout << a.minWindow(test, 3) << endl;
  return 0;
}
