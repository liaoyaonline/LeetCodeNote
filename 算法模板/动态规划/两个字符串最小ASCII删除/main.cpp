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
  int minWindow(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
      dp[i][0] = dp[i - 1][0] + (int)s1[i - 1];
    }
    for (int i = 1; i <= m; i++) {
      dp[0][i] = dp[0][i - 1] + (int)s2[i - 1];
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (s1[i - 1] == s2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          if (dp[i][j - 1] + s2[j - 1] > dp[i - 1][j] + s1[i - 1]) {
            dp[i][j] = dp[i - 1][j] + (int)s1[i - 1];
          } else {
            dp[i][j] = dp[i][j - 1] + (int)s2[j - 1];
          }
        }
      }
    }
    return dp[n][m];
  }
};
int main() {
  Solution a;
  string test1 = "delete";
  string test2 = "leet";
  cout << a.minWindow(test1, test2) << endl;
  return 0;
}
