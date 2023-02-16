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
  int minWindow(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<int> rows(n, 0);
    vector<int> cols(m, 0);
    int nums = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        if (mat[i][j] == 1) {
          rows[i]++;
          cols[j]++;
        }
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1) nums++;
    return nums;
  }
};
int main() {
  Solution a;
  vector<vector<int>> test{
      {0, 0, 0, 1}, {1, 0, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
  cout << a.minWindow(test) << endl;
  return 0;
}
