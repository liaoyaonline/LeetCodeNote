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
  void backtrack(vector<vector<int>>& res, vector<int>& nums, int len) {
    for (int i = 0; i < len - 1; i++) {
      for (int j = i + 1; j < len; j++) {
        swap(nums[i], nums[j]);
        res.push_back(nums);
        swap(nums[i], nums[j]);
      }
    }
  }
  int minWindow(vector<int>& nums, vector<int> nums2) {
    vector<vector<int>> res;
    backtrack(res, nums, nums.size());
    vector<int> zeroindex;
    for (int i = 0; i < nums2.size(); i++) {
      if (nums2[i] == 0) zeroindex.push_back(i);
    }
    int errornums = 0;
    for (int i = 0; i < res.size(); i++) {
      int flag = 0;
      for (int j = 0; j < zeroindex.size(); j++) {
        flag = flag || res[i][zeroindex[j]];
      }
      if (flag == 1) {
        errornums++;
      }
    }
    return errornums;
  }
};
int main() {
  Solution a;
  /*int N;
  cin >> N;
  int K;
  cin >> K;
  vector<int> test;
  for (int i = 0; i < N; i++) test.push_back(i + 1);
  */
  string tempstr1;
  string tempstr2;
  vector<int> test;
  vector<int> test2;
  cin >> tempstr1;
  cin >> tempstr2;
  for (int i = 0; i < tempstr1.size(); i++) {
    string tempchar;
    tempchar.push_back(tempstr1[i]);
    test.push_back(atoi(tempchar.c_str()));
  }
  for (int i = 0; i < tempstr2.size(); i++) {
    string tempchar;
    tempchar.push_back(tempstr2[i]);
    test2.push_back(atoi(tempchar.c_str()));
  }
  cout << a.minWindow(test, test2) << endl;
  return 0;
}
