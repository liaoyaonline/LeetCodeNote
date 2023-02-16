/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin() bool cmp(const word &num1, const word &num2) {
  return num1.value != num2.value ? num1.value > num2.value: num1.name <
 num2.name;} v.insert(v.begin()+3,1);map.containsKey(num) s.substr(i,2)####
priority_queue<int, vector<int>, greater<>> pq;//小根堆
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
bool cmp(vector<int> u, vector<int> v) { return u[1] < v[1]; }
class Solution {
 public:
  int minWindow(vector<vector<int>>& points) {
    sort(points.begin(), points.end(),
         [](const vector<int> u, const vector<int> v) { return u[1] < v[1]; });
    int sum = 1;
    int flag = points[0][1];
    for (int i = 0; i < points.size(); i++) {
      if (points[i][0] > flag) {
        flag = points[i][1];
        sum++;
      }
    }
    return res;
  }
};
int main() {
  Solution a;
  vector<vector<int>> test{{10, 16}, {2, 8}, {1, 6}, {7, 12}};
  cout << a.minWindow(test) << endl;
  return 0;
}
