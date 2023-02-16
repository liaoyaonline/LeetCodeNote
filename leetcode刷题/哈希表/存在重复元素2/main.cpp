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
  bool minWindow(vector<int>& nums, int k) {
    map<int, int> hashmap;
    for (int i = 0; i < nums.size(); i++) {
      if (hashmap.find(nums[i]) != hashmap.end() && i - hashmap[nums[i]] <= k)
        return true;
      hashmap[nums[i]] = i;
    }
    return false;
  }
};
int main() {
  Solution a;
  vector<int> test{1, 2, 3, 1, 2, 3};
  cout << a.minWindow(test, 2) << endl;
  return 0;
}
