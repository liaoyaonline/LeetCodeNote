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
  long long res;

 public:
  void backtrack(vector<int>& nums, int index, int currlen, int maxlen, int len,
                 int currmax, int currmin, int minK, int maxK) {
    if (currlen == maxlen) {
      if (currmin == minK && currmax == minK) res++;
      return;
    }
    if (index == len) {
      return;
    }
    for (int i = index; i < len; i++) {
      int tempmin = currmin;
      tempmin = min(tempmin, nums[i]);
      int tempmax = currmax;
      tempmax = max(tempmax, nums[i]);
      backtrack(nums, i + 1, currlen + 1, maxlen, len, tempmax, tempmin, minK,
                maxK);
    }
  }
  long long minWindow(vector<int>& nums, int minK, int maxK) {
    res = 0;
    for (int i = 0; i < nums.size(); i++) {
      backtrack(nums, 0, 0, i, nums.size(), INT_MIN, INT_MAX, minK, maxK);
    }
    return res;
  }
};
int main() {
  Solution a;
  vector<int> test{1, 3, 5, 2, 7, 5};
  cout << a.minWindow(test, 1, 5) << endl;
  return 0;
}
