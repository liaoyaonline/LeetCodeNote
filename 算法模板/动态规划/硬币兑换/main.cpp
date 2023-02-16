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
  int minWindow(vector<int>& coins, int amount) {
    int n = coins.size();
    int m = amount;
    vector<int> dp(m + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (j - coins[i - 1] >= 0)
          dp[j] = dp[j] + dp[j - coins[i - 1]];
        else
          dp[j] = dp[j];
      }
    }
    return dp[m];
  }
};
int main() {
  Solution a;
  vector<int> test{1, 2, 5};
  cout << a.minWindow(test, 5) << endl;
  return 0;
}
