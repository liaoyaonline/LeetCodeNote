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
  int seat(vector<int>& seat, int N) {
    if (seat.size() <= 1 && seat[0] == 0) {
      seat[0] = 1;
      return 0;
    }
    vector<int> dp(N, 0);
    for (int i = N - 1; i >= 0; i--) {
      if (seat[i] != 0) continue;
      for (int k = 1; i + k < N || i - k >= 0; k++) {
        dp[i] = k;
        if (i - k < 0 && i + k < N && seat[i + k] != 0) break;
        if (i - k >= 0 && i + k >= N && seat[i - k] != 0) break;
        if (i - k >= 0 && i + k < N) {
          if (seat[i - k] == 1 || seat[i + k] == 1) break;
        }
      }
    }
    int maxlen = 0;
    int flag = -1;
    for (int i = N - 1; i >= 0; i--) {
      if (dp[i] >= maxlen && dp[i] >= 1) {
        maxlen = dp[i];
        flag = i;
      }
    }
    if (flag != -1) seat[flag] = 1;
    return flag;
  }
  void leavel(vector<int>& seat, int num) { seat[num] = 0; }
};
int main() {
  Solution a;
  int N = 0;
  cin >> N;
  vector<int> test(N, 0);
  int num;
  while (cin >> num) {
    if (num < 0)
      a.leavel(test, -num);
    else
      cout << a.seat(test, N) << endl;
  }
  return 0;
}
