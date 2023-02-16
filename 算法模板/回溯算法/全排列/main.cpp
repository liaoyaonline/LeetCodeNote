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
  int result;
  vector<vector<int>> res;
  void backtrack(vector<int>& nums, vector<int> path, int k, int start,
                 int cnt) {
    if (cnt >= k) {
      res.push_back(path);
    }
    for (int i = start; i < nums.size(); i++) {
      vector<int> newpath = path;
      newpath.push_back(nums[i]);
      backtrack(nums, newpath, k, i + 1, cnt + 1);
    }
  }
  vector<vector<int>> minWindow(vector<int>& nums, int k) {
    vector<int> path;
    backtrack(nums, path, k, 0, 0);
    sort(res.begin(), res.end());
    return res;
  }
};
int main() {
  Solution a;
  vector<int> test{1, 2, 3};
  vector<vector<int>> res = a.minWindow(test, 2);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) cout << res[i][j] << " ";
    cout << endl;
  }
  return 0;
}
