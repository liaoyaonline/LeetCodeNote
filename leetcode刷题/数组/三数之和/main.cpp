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
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    set<vector<int>> tempres;
    if (nums.empty() || nums.size() < 3) return res;
    sort(nums.begin(), nums.end());
    if (nums[0] > 0) return res;
    for (int i = 0; i < nums.size() - 2; i++) {
      int l = i + 1;
      int r = nums.size() - 1;
      if (i > 1 && nums[i] == nums[i - 1]) continue;
      while (l < r) {
        if ((nums[i] + nums[l] + nums[r]) > 0)
          r--;
        else if ((nums[i] + nums[l] + nums[r]) < 0)
          l++;
        else {
          vector<int> tempnum;
          tempnum.push_back(nums[i]);
          tempnum.push_back(nums[l]);
          tempnum.push_back(nums[r]);
          tempres.insert(tempnum);
          l++;
        }
      }
    }
    for (auto it = tempres.begin(); it != tempres.end(); it++)
      res.push_back(*it);
    return res;
  }
};
int main() {
  Solution a;
  int b[6] = {-1, 0, 1, 2, -1, -4};
  vector<int> test(b, b + 6);
  vector<vector<int>> result = a.threeSum(test);
  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result.size(); j++) cout << result[i][j] << " ";
    cout << endl;
  }
  return 0;
}
