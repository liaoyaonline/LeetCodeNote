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
  int minWindow(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      int minnum = i;
      for (int j = 1; j * j <= i; j++) {
        int tempnum = i - (j * j);
        minnum = min(dp[tempnum], minnum);
      }
      dp[i] = minnum + 1;
    }
    return dp[n];
  }
};
int main() {
  Solution a;
  cout << a.minWindow(12) << endl;
  return 0;
}
