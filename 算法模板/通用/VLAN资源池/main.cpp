/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin() bool cmp(const word &num1, const word &num2) {
  return num1.value != num2.value ? num1.value > num2.value: num1.name <
 num2.name;} v.insert(v.begin()+3,1);map.containsKey(num) s.substr(i,2)####
string b= to_string(int a); int a = atoi(b.c_str());*/
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
bool cmp(vector<int> u, vector<int> v) { return u[0] < v[0]; }
class Solution {
 public:
  vector<vector<int>> split(string s, char ch) {
    vector<vector<int>> res;
    vector<int> tempnums;
    if (s.empty()) return res;
    string tempstr = "";
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ',') {
        int tempnum = atoi(tempstr.c_str());
        tempnums.push_back(tempnum);
        if (tempnums.size() == 1) tempnums.push_back(tempnum);
        tempstr = "";
        res.push_back(tempnums);
        vector<int> temp;
        tempnums = temp;
        continue;
      }
      if (s[i] == ch) {
        int tempnum = atoi(tempstr.c_str());
        tempnums.push_back(tempnum);
        tempstr = "";
        continue;
      }
      tempstr.push_back(s[i]);
    }
    int tempnum2 = atoi(tempstr.c_str());
    tempnums.push_back(tempnum2);
    res.push_back(tempnums);
    return res;
  }
  int minWindow(vector<vector<int>>& nums, int target) {
    sort(nums.begin(), nums.end(), cmp);
    for (int i = 0; i < nums.size(); i++) {
      if (target < nums[i][0]) break;
      if (nums[i][0] == nums[i][1] && nums[i][0] == target) {
        nums.erase(nums.begin() + i);
        break;
      }
      if (target >= nums[i][0] && target <= nums[i][1]) {
        if (target == nums[i][0]) {
          break;
        }
        if (target == nums[i][1]) {
          break;
        }
        if (target > nums[i][0] && target < nums[i][1]) {
          vector<int> test1{nums[i][0], target - 1};
          vector<int> test2{target + 1, nums[i][1]};
          nums.emplace(nums.begin() + i + 1, test2);
          nums.emplace(nums.begin() + i + 1, test1);
          nums.erase(nums.begin() + i);
          break;
        }
      }
    }
    return 0;
  }
};
int main() {
  Solution a;
  string teststr;
  cin >> teststr;
  int target;
  cin >> target;
  vector<vector<int>> test = a.split(teststr, '-');
  a.minWindow(test, target);
  for (int i = 0; i < test.size() - 1; i++) {
    if (test[i][0] == test[i][1]) {
      cout << test[i][0] << ",";
      continue;
    }
    cout << test[i][0] << "-" << test[i][1] << ",";
  }
  if (test[test.size() - 1][0] == test[test.size() - 1][1]) {
    cout << test[test.size() - 1][0] << endl;
  } else
    cout << test[test.size() - 1][0] << "-" << test[test.size() - 1][1] << endl;
  return 0;
}
