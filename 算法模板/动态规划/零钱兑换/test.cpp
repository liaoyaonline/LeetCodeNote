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
  int minWindow(vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    if (amount < 0) return -1;
    int res = INT_MAX;
    for (int i = 0; i < coins.size(); i++) {
      int tempnum = minWindow(coins, amount - coins[i]);
      if (tempnum == -1) continue;
      res = min(res, tempnum + 1);
    }
    return res == INT_MAX ? -1 : res;
  }
};
int main() {
  Solution a;
  vector<int> test{2};
  cout << a.minWindow(test, 3) << endl;
  return 0;
}
