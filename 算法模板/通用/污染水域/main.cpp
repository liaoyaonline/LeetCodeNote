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
  bool checknum(vector<vector<int>> nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (nums[i][j] == 0) return false;
      }
    }
    return true;
  }
  int minWindow(vector<vector<int>> nums) {
    int n = nums.size();
    int ret = 0;
    int flag = 0;
    for (int i = 0; i < n && flag == 0; i++) {
      for (int j = 0; j < n; j++) {
        if (nums[i][j] == 1) {
          flag = 1;
          break;
        }
      }
    }
    if (flag == 0) return -1;
    while (!checknum(nums)) {
      ret++;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (nums[i][j] == 1) {
            if (i >= 0 && i < n && j - 1 >= 0 && j - 1 < n &&
                nums[i][j - 1] == 0)
              nums[i][j - 1] = 2;
            if (i >= 0 && i < n && j + 1 >= 0 && j + 1 < n &&
                nums[i][j + 1] == 0)
              nums[i][j + 1] = 2;
            if (i - 1 >= 0 && i - 1 < n && j >= 0 && j < n &&
                nums[i - 1][j] == 0)
              nums[i - 1][j] = 2;
            if (i + 1 >= 0 && i + 1 < n && j >= 0 && j < n &&
                nums[i + 1][j] == 0)
              nums[i + 1][j] = 2;
          }
        }
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (nums[i][j] == 2) nums[i][j] = 1;
        }
      }
    }
    return ret;
  }
};
int main() {
  Solution a;
  vector<vector<int>> test{{0, 0}, {0, 0}};
  cout << a.minWindow(test) << endl;
  return 0;
}
