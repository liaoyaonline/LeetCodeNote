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
struct T {
  int val;
  int mindp;
};
class Solution {
 public:
  int minWindow(vector<vector<int>>& dungeon) {
    int n = dungeon.size();
    int m = dungeon[0].size();
    vector<vector<T>> dp(n, vector<T>(m));
    dp[0][0].val = dungeon[0][0];
    dp[0][0].mindp = dungeon[0][0];
    for (int i = 1; i < n; i++) {
      dp[i][0].val = dp[i - 1][0].val + dungeon[i][0];
      dp[i][0].mindp = min(dp[i][0].val, dp[i - 1][0].mindp);
    }
    for (int i = 1; i < m; i++) {
      dp[0][i].val = dp[0][i - 1].val + dungeon[0][i];
      dp[0][i].mindp = min(dp[0][i].val, dp[0][i - 1].mindp);
    }
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        int minleft = min(dp[i][j - 1].val + dungeon[i][j], dp[i][j - 1].mindp);
        int minup = min(dp[i - 1][j].val + dungeon[i][j], dp[i - 1][j].mindp);
        if (minleft > minup) {
          dp[i][j].val = dp[i][j - 1].val + dungeon[i][j];
          dp[i][j].mindp = min(dp[i][j].val, dp[i][j - 1].mindp);
        } else {
          dp[i][j].val = dp[i - 1][j].val + dungeon[i][j];
          dp[i][j].mindp = min(dp[i][j].val, dp[i - 1][j].mindp);
        }
      }
    }
    return dp[n - 1][m - 1].mindp <= 0 ? 1 - dp[n - 1][m - 1].mindp : 1;
  }
};
int main() {
  Solution a;
  vector<vector<int>> test{{1, -3, 3},
                           {0, -2, 0},
                           {-3, -3, -3}};  //算法缺陷，当dp[1,2]时会优先向左，
  cout
      << a.minWindow(test)
      << endl;  //但是当dp[2,2]时，如果dp[1,2]向上走会整体更优，即在状态计算方程有问题，
  //该状态下的局部最优没有转化为整体最优
  return 0;
}
