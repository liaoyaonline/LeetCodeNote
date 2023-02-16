/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() vector<string> s = split(str,'/')####
 */
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
  int maxSubArray(vector<int>& nums) {
    vector<int> dp;
    int maxsum = nums[0];
    dp.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
      if (dp[i - 1] < 0)
        dp.push_back(nums[i]);
      else
        dp.push_back(nums[i] + dp[i - 1]);
    }
    for (int i = 0; i < dp.size(); i++) maxsum = max(maxsum, dp[i]);
    return maxsum;
  }
};
int main() {
  Solution a;
  int num[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  vector<int> nums(num, num + 9);
  cout << a.maxSubArray(nums) << endl;
  return 0;
}
