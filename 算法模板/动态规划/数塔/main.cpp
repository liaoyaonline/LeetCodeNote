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
  int minWindow(vector<vector<int>>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++) dp[n - 1][i] = nums[n - 1][i];
    for (int i = n - 2; i >= 0; i--) {
      for (int m = 0; m <= i; m++) {
        dp[i][m] = max(dp[i + 1][m], dp[i + 1][m + 1]) + nums[i][m];
      }
    }
    return dp[0][0];
  }
};
int main() {
  Solution a;
  vector<vector<int>> test{
      {7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};
  cout << a.minWindow(test) << endl;
  return 0;
}
