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
  int minWindow(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> dp(row, vector<int>(col));
    dp[row - 1] = matrix[row - 1];
    for (int i = row - 2; i >= 0; i--) {
      for (int j = 0; j < col; j++) {
        dp[i][j] = dp[i + 1][j] + matrix[i][j];
        if (j - 1 >= 0)
          dp[i][j] = min(dp[i][j], dp[i + 1][j - 1] + matrix[i][j]);
        if (j + 1 < col)
          dp[i][j] = min(dp[i][j], dp[i + 1][j + 1] + matrix[i][j]);
      }
    }
    int mindp = INT_MAX;
    for (int i = 0; i < col; i++) mindp = min(mindp, dp[0][i]);
    return mindp;
  }
};
int main() {
  Solution a;
  vector<vector<int>> test{{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
  cout << a.minWindow(test) << endl;
  return 0;
}
