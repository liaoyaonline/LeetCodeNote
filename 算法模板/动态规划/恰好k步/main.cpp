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
  const int MOD = 1000000007;

 public:
  int minWindow(int startPos, int endPos, int k) {
    int d = abs(endPos - startPos);
    if (d > k || (d + k) % 2 == 1) return 0;
    vector<vector<long long>> f;
    f.resize(k + 1, vector<long long>(k + 1));
    for (int i = 0; i <= k; i++) {
      f[i][0] = 1;
      for (int j = 1; j <= i; j++)
        f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % MOD;
    }
    return f[k][(d + k) / 2];
  }
};
int main() {
  Solution a;
  cout << a.minWindow(1, 2, 3) << endl;
  return 0;
}
