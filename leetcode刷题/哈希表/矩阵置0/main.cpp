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
  bool minWindow(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> x(n, 1);
    vector<int> y(m, 1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == 0) {
          x[i] = 0;
          y[j] = 0;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (x[i] == 0 || y[j] == 0) matrix[i][j] = 0;
      }
    }
  }
};
int main() {
  Solution a;
  vector<vector<int>> test{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  a.minWindow(test);
  for (int i = 0; i < test.size(); i++) {
    for (int j = 0; j < test[0].size(); j++) cout << test[i][j] << " ";
    cout << endl;
  }
  return 0;
}
