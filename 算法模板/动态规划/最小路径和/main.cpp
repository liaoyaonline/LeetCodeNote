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
  int minWindow(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = grid[0][0];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i == 0 && j > 0) dp[i][j] = dp[i][j - 1] + grid[i][j];
        if (j == 0 && i > 0) dp[i][j] = dp[i - 1][j] + grid[i][j];
        if (i > 0 && j > 0)
          dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
      }
    }
    return dp[n - 1][m - 1];
  }
};
int main() {
  Solution a;
  vector<vector<int>> test{{1, 2, 3}, {4, 5, 6}};
  cout << a.minWindow(test) << endl;
  return 0;
}
