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
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
  vector<vector<int>> res;

 public:
  vector<int> split(string s) {
    vector<int> res;
    for (int i = 0; i < s.size(); i++) {
      int tempnum = (int)s[i];
      res.push_back(tempnum);
    }
    return res;
  }
  void dfs(vector<int> nums, vector<int>& path, int index, int n) {
    if (index == n) {
      res.push_back(path);
    }
    int sum = 0;
    for (int i = index; i < n; i++) {
      sum += nums[i];
      if (sum == 153) {
        vector<int> temppath = path;
        temppath.push_back(153);
        dfs(nums, temppath, i + 1, n);
      }
      if (sum == 370) {
        vector<int> temppath = path;
        temppath.push_back(370);
        dfs(nums, temppath, i + 1, n);
      }
      if (sum == 371) {
        vector<int> temppath = path;
        temppath.push_back(371);
        dfs(nums, temppath, i + 1, n);
      }
      if (sum == 407) {
        vector<int> temppath = path;
        temppath.push_back(407);
        dfs(nums, temppath, i + 1, n);
      }
    }
  }
  int sortedArrayToBST(vector<int> nums) {
    int n = nums.size();
    vector<int> path;
    dfs(nums, path, 0, n);
    if (res.empty()) return 0;
    if (res.size() == 1) return res[0].size();
    if (res.size() > 1) return -1;
    return res[0].size();
  }
};
int main() {
  Solution a;
  string teststr;
  cin >> teststr;
  vector<int> test = a.split(teststr);
  cout << a.sortedArrayToBST(test) << endl;
  return 0;
}
