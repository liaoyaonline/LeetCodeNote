/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin() bool cmp(const word &num1, const word &num2) {
  return num1.value != num2.value ? num1.value > num2.value: num1.name <
 num2.name;} v.insert(v.begin()+3,1);map.containsKey(num) s.substr(i,2)####
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
class Solution {
 public:
  int m, n, ans = 0;
  void dfs(vector<vector<int>>& mat, int c, int num, int p) {
    if (num == c) {
      int tmp = 0;
      for (int i = 0; i < m; i++) {
        int flag = 1;
        for (int j = 0; j < n; j++)
          if (mat[i][j] == 1) flag = 0;
        if (flag == 1) tmp++;
      }
      ans = max(tmp, ans);
      return;
    }
    for (int k = p; k <= n - c + num; k++) {
      for (int i = 0; i < m; i++) {
        if (mat[i][k] == 1) mat[i][k] = 2;
      }
      dfs(mat, c, num + 1, k + 1);
      for (int i = 0; i < m; i++)
        if (mat[i][k] == 2) mat[i][k] = 1;
    }
  }
  int minWindow(vector<vector<int>>& mat, int cols) {
    int n = mat.size(), m = mat[0].size();
    dfs(mat, cols, 0, 0);
    return ans;
  }
};
int main() {
  Solution a;
  vector<vector<int>> test{{0, 0, 0}, {1, 0, 1}, {0, 1, 1}, {0, 0, 1}};
  cout << a.minWindow(test, 2) << endl;
  return 0;
}
