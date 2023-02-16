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
  int minWindow(string s) {
    int n = s.size();
    vector<vector<int>> lcp(n + 1, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        if (s[i] == s[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
      }
    }
    vector<int> dp(n, 0);
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 1; i + j * 2 <= n; ++j)
        if (lcp[i][i + j] >= j) dp[i] = max(dp[i], dp[i + j]);
      dp[i]++;
    }
    return dp[0];
  }
};
int main() {
  Solution a;
  string test = "aaaaaaaaaaa";
  cout << a.minWindow(test) << endl;
  return 0;
}
