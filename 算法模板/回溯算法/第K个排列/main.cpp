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
  void backtrack(vector<vector<int>>& res, vector<int>& nums, int firsts,
                 int len) {
    if (firsts == len) {
      res.push_back(nums);
      return;
    }
    for (int i = firsts; i < len; i++) {
      swap(nums[firsts], nums[i]);
      backtrack(res, nums, firsts + 1, len);
      swap(nums[firsts], nums[i]);
    }
  }
  vector<int> minWindow(vector<int>& nums, int K) {
    vector<vector<int>> res;
    backtrack(res, nums, 0, nums.size());
    return res[K - 1];
  }
};
int main() {
  Solution a;
  int N;
  cin >> N;
  int K;
  cin >> K;
  vector<int> test;
  for (int i = 0; i < N; i++) test.push_back(i + 1);
  vector<int> result = a.minWindow(test, K);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i];
  }
  cout << endl;
  return 0;
}
