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
  int getlen(vector<int> hashmap, int remain) {
    int minlen = 0;
    for (int i = remain; i >= 0; i--) {
      if (hashmap[i] == 1) {
        return minlen;
      }
      minlen++;
    }
    return minlen;
  }
  int minWindow(vector<int>& nums, int target) {
    vector<int> hashmap(1000, 0);
    sort(nums.begin(), nums.end());
    int minlen = target;
    if (nums[0] + nums[1] + nums[2] > target) return -1;
    for (int i = 0; i < nums.size(); i++) hashmap[nums[i]] = 1;
    for (int i = 0; i < nums.size() - 2; i++) {
      for (int j = i + 1; j < nums.size() - 1; j++) {
        int remain = target - nums[i] - nums[j];
        if (remain >= nums[j + 1]) {
          int currminlen = getlen(hashmap, remain);
          minlen = min(minlen, currminlen);
        }
      }
    }
    return target - minlen;
  }
};
int main() {
  Solution a;
  string teststr;
  vector<int> test;
  int target;
  cin >> teststr;
  cin >> target;
  string tempstr = "";
  for (int i = 0; i < teststr.size(); i++) {
    if (teststr[i] == ',') {
      int tempnum = atoi(tempstr.c_str());
      test.push_back(tempnum);
      tempstr = "";
      continue;
    }
    tempstr.push_back(teststr[i]);
  }
  int tempnum2 = atoi(tempstr.c_str());
  test.push_back(tempnum2);
  cout << a.minWindow(test, target) << endl;
  return 0;
}
