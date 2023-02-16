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
    vector<vector<int>> dp(n+1, vector<int>(m+1,INT_MAX));
    dp[n][m - 1] = dp[n-1][m] = 1;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {
        int tempmin = min(dp[i][j + 1], dp[i + 1][j]);
        dp[i][j] = max(tempmin - dungeon[i][j], 1);
      }
    }
    return dp[0][0];
  }
};
int main() {
  Solution a;
  vector<vector<int>> test{{0, -3}};
  cout << a.minWindow(test) << endl;
  return 0;
}
