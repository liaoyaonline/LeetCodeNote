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
 public:
  void dfs(vector<vector<int>>& nums, int& countnum, int x, int y, int maxn,
           int maxm) {
    if (x < 0 || x >= maxn || y < 0 || y >= maxm) return;
    if (nums[x][y] == 1) return;
    if (nums[x][y] == 2) {
      nums[x][y] = 1;
      countnum++;
    }
    if (countnum == 2) return;
    nums[x][y] = 1;
    dfs(nums, countnum, x + 1, y, maxn, maxm);
    dfs(nums, countnum, x - 1, y, maxn, maxm);
    dfs(nums, countnum, x, y + 1, maxn, maxm);
    dfs(nums, countnum, x, y - 1, maxn, maxm);
  }
  int sortedArrayToBST(vector<vector<int>>& nums) {
    int n = nums.size();
    int m = nums[0].size();
    int res = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (nums[i][j] == 3) {
          vector<vector<int>> tempnums = nums;
          int currnum = 0;
          dfs(tempnums, currnum, i, j, n, m);
          if (currnum == 2) res++;
        }
      }
    }
    return res;
  }
};
int main() {
  Solution a;
  vector<vector<int>> test{
      {2, 1, 2, 3}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}};
  cout << a.sortedArrayToBST(test) << endl;
  return 0;
}
