/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin() bool cmp(const word &num1, const word &num2) {
  return num1.value != num2.value ? num1.value > num2.value: num1.name <
 num2.name;} v.insert(v.begin()+3,1);map.containsKey(num)####
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
  int minWindow(vector<int>& chargeTimes,vector<int>& runningCosts,long long budget) {
      int n = chargeTimes.size();
      long long runsum = 0;
      long long tempsum = 0;
      int maxnum = chargeTimes[0];
      int templen = 0;
      int maxlen = 0;
      vector<int> nums;
      for(int l = 0,r = 0; r < n; r++)
      {
          while(l < r && isum + maxnum > budget)
          {
              nums.pop();
              vector<int> tempnums = nums;
              sort(tempnums.begin(),tempnums.end());
              maxnum = tempnums[tempnums.size() - 1];
              if()
          }
          templen = r - l + 1;
          runsum += (templen * runningCosts[r] + tempsum);
          tempsum += runningCosts[r];
          maxlen = max(templen,maxlen);
          nums.push(chargeTimes[r]);
          vector<int> tempnum
      }
      return true; }
};
int main() {
  Solution a;
  a.minWindow();
  return 0;
}
