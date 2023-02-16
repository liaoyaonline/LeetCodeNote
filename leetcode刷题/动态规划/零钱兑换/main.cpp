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
    vector<int> dp(amount + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
      int minnum = INT_MAX;
      for (int j = 0; j < coins.size(); j++) {
        if (i - coins[j] < 0 || dp[i - coins[j]] == -1) continue;
        minnum = min(minnum, dp[i - coins[j]] + 1);
      }
      if (minnum != INT_MAX) dp[i] = minnum;
    }
    return dp[amount];
  }
};
int main() {
  Solution a;
  vector<int> test{2};
  cout << a.minWindow(test, 3) << endl;
  return 0;
}
