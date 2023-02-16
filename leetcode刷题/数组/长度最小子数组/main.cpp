/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..)####
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
  int minSubArrayLen(int target, vector<int>& nums) {
    int minlen = nums.size();
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
    }
    if (sum < target) return 0;
    sum = 0;
    for (int l = 0, r = 0; r < nums.size(); r++) {
      sum += nums[r];
      while (sum >= target) {
        minlen = min(minlen, r - l + 1);
        sum = sum - nums[l];
        l++;
      }
    }
    return minlen;
  }
};
int main() {
  Solution a;
  int b[6] = {1, 2, 3, 4, 5};
  vector<int> nums(b, b + 5);
  cout << a.minSubArrayLen(11, nums) << endl;
  return 0;
}
