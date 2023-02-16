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
  int minWindow(vector<vector<int>>& nums, int V) {
    int n = nums.size();
    vector<int> v(n + 1, 0);
    vector<int> w(n + 1, 0);
    vector<int> dp(V + 1, 0);
    for (int i = 1; i <= n; i++) {
      v[i] = nums[i - 1][0];
      w[i] = nums[i - 1][1];
    }
    for (int i = 1; i <= n; i++) {
      for (int j = V; j >= 0; j--) {
        if (v[i] <= j)
          dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        else
          dp[j] = dp[j];
      }
    }
    return dp[V];
  }
};
int main() {
  Solution a;
  vector<vector<int>> test{{1, 2}, {2, 4}, {3, 4}, {4, 5}};
  cout << a.minWindow(test, 5) << endl;
  return 0;
}
