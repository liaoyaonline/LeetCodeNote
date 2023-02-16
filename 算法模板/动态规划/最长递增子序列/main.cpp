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
  int minWindow(vector<int>& nums, int k) {
    int n = nums.size();
    int maxlen = 1;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
      for (int j = i; j >= 0; j--) {
        if (nums[i] > nums[j] && nums[i] - nums[j] <= k) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      maxlen = max(dp[i], maxlen);
    }
    return maxlen;
  }
};
int main() {
  Solution a;
  vector<int> test{7, 4, 5, 1, 8, 12, 4, 7};
  cout << a.minWindow(test, 5) << endl;
  return 0;
}
