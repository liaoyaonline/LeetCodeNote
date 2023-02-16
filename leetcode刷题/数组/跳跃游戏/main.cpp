/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin()####
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
  bool canJump(vector<int>& nums) {
    int maxright = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (i <= maxright) {
        maxright = max(maxright, nums[i] + i);
        if (maxright >= nums.size() - 1) return true;
      }
    }
    return false;
  }
};
int main() {
  Solution a;
  int b[5] = {3, 2, 1, 1, 4};
  vector<int> nums(b, b + 5);
  cout << a.canJump(nums) << endl;
  return 0;
}
