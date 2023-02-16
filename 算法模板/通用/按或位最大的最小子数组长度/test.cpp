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
  vector<int> minWindow(vector<int> nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    vector<int> res(n, 0);
    dp[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      dp[i] = nums[i] | dp[i + 1];
    }
    for (int i = 0; i < n; i++) {
      int sum = nums[i];
      for (int l = i; l < n; l++) {
        sum = sum | nums[l];
        if (sum == dp[i]) {
          res[i] = l - i + 1;
          break;
        }
      }
    }
    return res;
  }
};
int main() {
  Solution a;
  vector<int> test{1, 0, 2, 1, 3};
  vector<int> res = a.minWindow(test);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}
