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
bool cmp(vector<int> u, vector<int> v) {
  return u[0] != v[0] ? u[0] < v[0] : u[1] < v[1];
}
class Solution {
 public:
  int minWindow(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(), [](vector<int> u, vector<int> v) {
      return u[0] != v[0] ? u[0] < v[0] : u[1] > v[1];
    });
    vector<int> dp(envelopes.size(), 1);
    int maxdp = 1;
    for (int i = 0; i < envelopes.size(); i++) {
      int maxnum = 1;
      for (int j = i; j >= 0; j--) {
        if (envelopes[i][1] > envelopes[j][1]) maxnum = max(maxnum, dp[j] + 1);
      }
      dp[i] = maxnum;
      maxdp = max(maxnum, maxdp);
    }
    return maxdp;
  }
};
int main() {
  Solution a;
  vector<vector<int>> test{{5, 4}, {6, 4}, {6, 7}, {2, 3}};
  cout << a.minWindow(test) << endl;
  return 0;
}
