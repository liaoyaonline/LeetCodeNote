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
  vector<int> split(string s, char ch) {
    vector<int> res;
    if (s.empty()) return res;
    string tempstr = "";
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ch) {
        int tempnum = atoi(tempstr.c_str());
        res.push_back(tempnum);
        tempstr = "";
        continue;
      }
      tempstr.push_back(s[i]);
    }
    int tempnum2 = atoi(tempstr.c_str());
    res.push_back(tempnum2);
    return res;
  }
  int getmaxnum(vector<int>& nums, int target) {
    int maxnum = -1;
    int flag = 0;
    int index = -1;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 9) return -1;
      if (nums[i] <= target && nums[i] > maxnum && nums[i] >= 0) {
        maxnum = nums[i];
        flag = 1;
        index = i;
      }
    }
    if (flag = 0) return -1;
    nums[index] = -1;
    return maxnum;
  }
  int minWindow(vector<int>& nums, vector<int>& res) {
    vector<int> maxnum(6, 0);
    maxnum[0] = 1;
    maxnum[1] = 9;
    maxnum[2] = 5;
    maxnum[3] = 9;
    maxnum[4] = 5;
    maxnum[5] = 9;
    int hmax = getmaxnum(nums, 2);
    if (hmax == -1) {
      cout << "invalid" << endl;
      return -1;
    }
    if (hmax == 2) {
      maxnum[0] = 2;
      maxnum[1] = 3;
    }
    res[0] = hmax;
    for (int i = 1; i < res.size(); i++) {
      int tempmax = getmaxnum(nums, maxnum[i]);
      if (tempmax == -1) {
        cout << "invalid" << endl;
        return -1;
      }
      res[i] = tempmax;
    }
    return 0;
  }
};
int main() {
  Solution a;
  vector<int> nums{0, 2, 3, 0, 5, 12};
  vector<int> res(nums.size(), 0);
  if (a.minWindow(nums, res) == 0) {
    cout << res[0] << res[1] << ':' << res[2] << res[3] << ':' << res[4]
         << res[5] << endl;
  }
  return 0;
}
