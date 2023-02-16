/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin() bool cmp(const word &num1, const word &num2) {
  return num1.value != num2.value ? num1.value > num2.value: num1.name <
 num2.name;} v.insert(v.begin()+3,1);map.containsKey(num) s.substr(i,2)####
string b= to_string(int a); int a =
atoi(b.c_str());d.emplace(d.begin()+1,4)在0后，1前面插入4
d.erase(d.begin()+1);删除1坐标上的数据*/
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
  int maxSum(vector<vector<int>>& grid) {
    int maxsum = INT_MIN;
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i <= n - 3; i++) {
      for (int j = 0; j <= m - 3; j++) {
        int tempmaxsum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2] +
                         grid[i + 1][j + 1] + grid[i + 2][j] +
                         grid[i + 2][j + 1] + grid[i + 2][j + 2];
        maxsum = max(tempmaxsum, maxsum);
      }
    }
    return maxsum;
  }
};
int main() {
  Solution a;
  vector<vector<int>> test{
      {6, 2, 1, 3}, {4, 2, 1, 5}, {9, 2, 8, 7}, {4, 1, 2, 9}};
  cout << a.maxSum(test) << endl;
  return 0;
}
