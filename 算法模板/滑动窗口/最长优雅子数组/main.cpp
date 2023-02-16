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
  int minWindow(vector<int>& nums) {
    int maxlen = 1;
    int result = 0;
    for (int l = 0, r = 0; r < nums.size(); r++) {
      while (l < r && (result & nums[r]) != 0) {
        result = result ^ nums[l];
        l++;
      }
      result |= nums[r];
      maxlen = max(maxlen, r - l + 1);
    }
    return maxlen;
  }
};
int main() {
  Solution a;
  vector<int> test{1090, 16384, 33, 1, 1, 1};
  cout << a.minWindow(test) << endl;
  int c = 1;
  int b = 3;
  return 0;
}
