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
bool cmp(vector<int> v, vector<int> u) { return v[1] < u[1]; }
class Solution {
 public:
  int minWindow(vector<vector<int>>& points) {
    int sum = 1;
    sort(points.begin(), points.end(), cmp);
    int flag = points[0][1];
    for (int i = 0; i < points.size(); i++) {
      if (points[i][0] > flag) {
        sum++;
        flag = points[i][1];
      }
    }
    return sum;
  }
};
int main() {
  Solution a;
  vector<vector<int>> test{{10, 16}, {2, 8}, {1, 6}, {7, 12}};
  cout << a.minWindow(test) << endl;
  return 0;
}
