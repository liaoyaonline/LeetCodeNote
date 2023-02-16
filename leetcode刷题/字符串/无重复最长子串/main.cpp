/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end()####
 */
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
  int lengthOfLongestSubstring(string s) {
    int nums[128] = {0};
    if (s.empty()) return 0;
    nums[(int)s[0]]++;
    int maxsublen = 1;
    for (int l = 0, r = 1; r < s.size(); r++) {
      int tempnum = (int)s[r];
      nums[tempnum]++;
      if (nums[tempnum] == 1) {
        maxsublen = max(maxsublen, (r - l + 1));
        continue;
      }
      while (nums[tempnum] > 1) {
        int templeft = (int)s[l];
        nums[templeft]--;
        l++;
      }
    }
    return maxsublen;
  }
};
int main() {
  Solution a;
  string strs;
  cin >> strs;
  cout << a.lengthOfLongestSubstring(strs) << endl;
  return 0;
}
