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
  vector<string> minWindow(int n) {
    vector<vector<string>> dp(n + 1);
    string temp = "()";
    dp[1].push_back(temp);
    temp = "";
    dp[0].push_back(temp);
    for (int i = 2; i <= n; i++) {
      for (int j = 0; j <= i - 1; j++) {
        for (int k = 0; k < dp[j].size(); k++) {
          for (int l = 0; l < dp[i - 1 - j].size(); l++) {
            string tempstr = "(" + dp[j][k] + ")" + dp[i - 1 - j][l];
            dp[i].push_back(tempstr);
          }
        }
      }
    }
    return dp[n];
  }
};
int main() {
  Solution a;
  vector<string> test = a.minWindow(3);
  for (int i = 0; i < test.size(); i++) cout << test[i] << endl;
  return 0;
}
