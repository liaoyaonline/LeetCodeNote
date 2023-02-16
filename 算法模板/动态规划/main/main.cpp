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
  int minWindow(vector<int>& nums) {
    vector<int> dp(nums.size(), 1);
    int maxdp = 1;
    for (int i = 1; i < nums.size(); i++) {
      int maxnum = INT_MIN;
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) maxnum = max(maxnum, dp[j] + 1);
      }
      if (maxnum != INT_MIN) {
        dp[i] = maxnum;
        maxdp = max(maxdp, dp[i]);
      }
    }
    return maxdp;
  }
};
int main() {
  Solution a;
  vector<int> test{1, 3, 6, 7, 9, 4, 10, 5, 6};
  cout << a.minWindow(test) << endl;
  return 0;
}
