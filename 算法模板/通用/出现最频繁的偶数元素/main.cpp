/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin() bool cmp(const word &num1, const word &num2) {
  return num1.value != num2.value ? num1.value > num2.value: num1.name <
 num2.name;} v.insert(v.begin()+3,1);map.containsKey(num) s.substr(i,2)####
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
    sort(nums.begin(), nums.end());
    map<int, int> hashmap;
    int currnum = -1;
    int maxnum = 0;
    for (int i = 0; i < nums.size(); i++) {
      hashmap[nums[i]]++;
      if (nums[i] % 2 == 0 && hashmap[nums[i]] > maxnum) {
        maxnum = hashmap[nums[i]];
        currnum = nums[i];
      }
    }
    return currnum;
  }
};
int main() {
  Solution a;
  vector<int> test{0, 1, 2, 2, 4, 4, 1};
  cout << a.minWindow(test) << endl;
  return 0;
}
