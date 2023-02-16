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
class Solution {
 public:
  int minWindow(vector<vector<int>> nums, int maxnum) {
    vector<int> dp(maxnum + 1, 0);
    vector<int> res(maxnum, 0);
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      int index = nums[i][0];
      int add = nums[i][1];
      dp[index] += nums[i][1];
    }
    res[0] = dp[0];
    for (int i = 1; i < maxnum; i++) {
      res[i] = res[i - 1] + dp[i];
    }
    for (int i = 0; i < maxnum; i++) {
      sum += abs(res[i]);
    }
    return sum;
  }
};
int main() {
  Solution a;
  int N;
  int maxnum;
  cin >> N;
  cin >> maxnum;
  vector<vector<int>> test(N, vector<int>(2, 0));
  for (int i = 0; i < N; i++) {
    cin >> test[i][0];
    cin >> test[i][1];
  }
  cout << a.minWindow(test, maxnum) << endl;
  return 0;
}
