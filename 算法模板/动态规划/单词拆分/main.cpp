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
  bool minWindow(string s, vector<string>& wordDict) {
    map<string, int> hashmap;
    int maxlen = 0;
    vector<bool> dp(s.size() + 1, false);
    for (int i = 0; i < wordDict.size(); i++) {
      hashmap[wordDict[i]] = 1;
      int temlen = wordDict[i].size();
      maxlen = max(maxlen, temlen);
    }
    for (int si = 1; si <= maxlen && si <= s.size(); si++) {
      string tempstr = s.substr(0, si);
      if (hashmap[tempstr] == 1) dp[si] = true;
    }
    for (int si = 1; si < s.size(); si++) {
      if (!dp[si]) continue;
      for (int k = 1; k <= maxlen && si + k <= s.size(); k++) {
        string tempstr = s.substr(si, k);
        if (hashmap[tempstr] == 1) dp[si + k] = true;
      }
    }
    return dp[s.size()];
  }
};
int main() {
  Solution a;
  vector<string> test2{"a"};
  string test = "a";
  cout << a.minWindow(test, test2) << endl;
  return 0;
}
