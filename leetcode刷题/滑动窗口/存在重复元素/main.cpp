/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin() bool cmp(const word &num1, const word &num2) {
  return num1.value != num2.value ? num1.value > num2.value: num1.name <
 num2.name;} v.insert(v.begin()+3,1);####
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
bool cmp(vector<int> num1, vector<int> num2) {
  return num1[0] != num2[0] ? num1[0] < num2[0] : num1[1] < num2[1];
}
class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    if (nums.size() == 1) return false;
    vector<vector<int>> res;
    for (int i = 0; i < nums.size(); i++) {
      vector<int> tempnum;
      tempnum.push_back(nums[i]);
      tempnum.push_back(i);
      res.push_back(tempnum);
    }
    sort(res.begin(), res.end(), cmp);
    for (int i = 0; i < res.size() - 1; i++) {
      if (res[i][0] == res[i + 1][0] && res[i + 1][1] - res[i][1] <= k)
        return true;
    }
    return false;
  }
};
int main() {
  Solution a;
  vector<int> test{1, 2, 3, 1, 2, 3};
  cout << a.containsNearbyDuplicate(test, 2) << endl;
  return 0;
}
