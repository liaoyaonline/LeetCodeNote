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
  int minWindow(string time) {
    vector<int> dp(5, 0);
    for (int i = 0; i < 5; i++) {
      if (time[i] == '?') dp[i] = 1;
    }
    int res = 1;
    if (dp[4] == 1) res *= 10;
    if (dp[3] == 1) res *= 6;
    if (dp[0] == 1 && dp[1] == 1) {
      res *= 24;
    }
    if (dp[0] == 1 && dp[1] == 0) {
      int tempnum = time[1] - '0';
      if (tempnum >= 4) {
        res *= 2;
      } else {
        res *= 3;
      }
    }
    if (dp[0] == 0 && dp[1] == 1) {
      int tempnum = time[0] - '0';
      if (tempnum <= 1) {
        res *= 10;
      } else {
        res *= 4;
      }
    }
    return res;
  }
};
int main() {
  Solution a;
  string test = "??:??";
  cout << a.minWindow(test) << endl;
  return 0;
}
