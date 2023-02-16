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
  int flag;
};
class Solution {
 public:
  int minWindow(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    vector<vector<T>> dp(n + 1, vector<T>(m + 1));
    for (int i = 0; i <= m; i++) {
      dp[0][i].val = i;
      dp[0][i].flag = 0;
    }
    for (int i = 0; i <= n; i++) {
      dp[i][0].val = i;
      dp[i][0].flag = 1;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j].val = dp[i - 1][j - 1].val;
          dp[i][j].flag = 3;
        }
        if (word1[i - 1] != word2[j - 1]) {
          dp[i][j].val = min(dp[i - 1][j].val, dp[i][j - 1].val) + 1;
          dp[i][j].val = min(dp[i][j].val, dp[i - 1][j - 1].val + 1);
          if (dp[i][j].val == dp[i][j - 1].val + 1) dp[i][j].flag = 0;
          if (dp[i][j].val == dp[i - 1][j].val + 1) dp[i][j].flag = 1;
          if (dp[i][j].val == dp[i - 1][j - 1].val + 1) dp[i][j].flag = 2;
        }
      }
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        cout << dp[i][j].flag << " ";
      }
      cout << endl;
    }
    return dp[n][m].val;
  }
};
int main() {
  Solution a;
  string test1 = "intention";
  string test2 = "execution";
  cout << a.minWindow(test1, test2) << endl;
  return 0;
}
