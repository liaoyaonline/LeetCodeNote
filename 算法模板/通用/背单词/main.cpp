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
  int minWindow(int wordnum, int day) {
    vector<int> dp(day + 1, 0);
    vector<int> lastday{2, 4, 7, 15, 30, 90, 180};
    for (int i = 1; i <= day; i++) {
      if (wordnum <= 2) {
        dp[i] = wordnum;
        wordnum = wordnum - dp[i];
      } else {
        dp[i] = 2;
        wordnum -= 2;
        if (i % 7 == 0 || i % 7 == 6) {
          dp[i] = 3;
          wordnum -= 1;
        }
      }
    }
    int res = dp[day];
    for (int i = 0; i < lastday.size(); i++) {
      if (day - lastday[i] + 1 <= 0) break;
      res += dp[day - lastday[i] + 1];
    }
    return res;
  }
};
int main() {
  Solution a;
  cout << a.minWindow(8, 9) << endl;
  return 0;
}
