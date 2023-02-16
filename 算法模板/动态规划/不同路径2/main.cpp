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
  int minWindow(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    if (obstacleGrid[0][0] == 1)
      dp[0][0] = 0;
    else
      dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
      if (obstacleGrid[i][0] == 1)
        dp[i][0] = 0;
      else
        dp[i][0] = dp[i - 1][0];
    }
    for (int i = 1; i < m; i++) {
      if (obstacleGrid[0][i] == 1)
        dp[0][i] = 0;
      else
        dp[0][i] = dp[0][i - 1];
    }
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        if (obstacleGrid[i][j] == 1)
          dp[i][j] = 0;
        else
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[n - 1][m - 1];
  }
};
int main() {
  Solution a;
  vector<vector<int>> test{{1, 0}};
  cout << a.minWindow(test) << endl;
  return 0;
}
