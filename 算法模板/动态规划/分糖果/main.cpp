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
  int minWindow(int nums) {
    vector<int> dp(nums + 1, 0);
    dp[1] = 0;
    for (int i = 2; i <= nums; i++) {
      if (i % 2 == 0) dp[i] = dp[i / 2] + 1;
      if (i % 2 != 0) dp[i] = min(dp[(i + 1) / 2], dp[(i - 1) / 2]) + 2;
    }
    return dp[nums];
  }
};
int main() {
  Solution a;
  int test;
  cin >> test;
  cout << a.minWindow(test) << endl;
  return 0;
}
