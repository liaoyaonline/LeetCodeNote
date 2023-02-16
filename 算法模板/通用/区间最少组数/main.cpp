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
  int minWindow(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(),
         [](vector<int> u, vector<int> v) { return u[1] < v[1]; });
    int pos = intervals[0][1];
    int ans = 1;
    for (int i = 0; i < intervals.size(); i++) {
      if (intervals[i][0] > pos) {
        pos = intervals[i][1];
        ++ans;
      }
    }
    return intervals.size() - ans == 0 ? 1 : intervals.size() - ans;
  }
};
int main() {
  Solution a;
  vector<vector<int>> test{{1, 3}, {5, 6}, {8, 10}, {11, 13}};
  cout << a.minWindow(test) << endl;
  return 0;
}
