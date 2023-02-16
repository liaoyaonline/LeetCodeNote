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
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  int minWindow(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    priority_queue<int, vector<int>, greater<>> test;
    test.push(intervals[0][1]);
    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i][0] <= test.top()) {
        test.push(intervals[i][1]);
      } else {
        test.pop();
        test.push(intervals[i][1]);
      }
    }
    return test.size();
  }
};
int main() {
  Solution a;
  vector<vector<int>> test{{1, 3}, {5, 6}, {8, 10}, {11, 13}};
  cout << a.minWindow(test) << endl;
  return 0;
}
