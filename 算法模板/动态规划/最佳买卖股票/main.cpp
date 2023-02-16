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
  int minWindow(vector<int>& prices) {
    int n = prices.size();
    int maxnum = 0;
    vector<vector<int>> dp(n + 1, vector<int>(5));
    dp[1][0] = -prices[0];
    dp[1][1] = 0;
    dp[1][2] = -prices[0];
    dp[1][3] = 0;
    dp[1][4] = 0;
    for (int i = 2; i <= n; ++i) {
      dp[i][0] = dp[i - 1][3] - prices[i - 1];
      dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + prices[i - 1];
      dp[i][2] = max(dp[i - 1][0], dp[i - 1][2]);
      dp[i][3] = max(dp[i - 1][1], dp[i - 1][3]);
      dp[i][4] = dp[i - 1][1];
    }
    maxnum = max(dp[n][0], dp[n][1]);
    maxnum = max(maxnum, dp[n][2]);
    maxnum = max(maxnum, dp[n][3]);
    maxnum = max(maxnum, dp[n][4]);
    return maxnum;
  }
};
int main() {
  Solution a;
  vector<int> test{1, 2, 3, 0, 2};
  cout << a.minWindow(test) << endl;
  return 0;
}
