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
  int minWindow(int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
      dp[0][i] = 1;
      dp[1][i] = 1;
    }
    for (int i = 1; i <= m; i++) dp[i][1] = 1;
    for (int i = 2; i <= m; i++) {
      for (int j = 2; j <= n; j++) {
        if (i < j)
          dp[i][j] = dp[i][i];
        else
          dp[i][j] = dp[i][j - 1] + dp[i - j][j];
      }
    }
    return dp[m][n];
  }
};
int main() {
  Solution a;
  int m = 0;
  int n = 0;
  cin >> m >> n;
  cout << a.minWindow(m, n) << endl;
  return 0;
}
