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
  vector<int> split(string s, char c) {
    vector<int> res;
    string tempstr = "";
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == c) {
        int tempnum = atoi(tempstr.c_str());
        res.push_back(tempnum);
        tempstr = "";
        continue;
      }
      tempstr.push_back(s[i]);
    }
    int tempnum = atoi(tempstr.c_str());
    res.push_back(tempnum);
    return res;
  }
  int minWindow(vector<int> nums, int sum) {
    int currsum = 0;
    int maxlen = -1;
    for (int l = 0, r = 0; r < nums.size(); r++) {
      currsum += nums[r];
      if (nums[r] > sum && r + 1 < nums.size())  //
      {
        l = r + 1;
        currsum = 0;
      }
      if (currsum == sum && r + 1 < nums.size()) {
        maxlen = max(maxlen, r - l + 1);
        l = r + 1;
        currsum = 0;
      }
      while (currsum > sum && l <= r) {
        sum -= nums[l];
        l++;
        if (currsum == sum && r + 1 < nums.size()) {
          maxlen = max(maxlen, r - l + 1);
          l = r + 1;
          currsum = 0;
          break;
        }
      }
    }
    if (nums[nums.size() - 1] == sum) maxlen = max(1, maxlen);
    return maxlen;
  }
};
int main() {
  Solution a;
  string test;
  cin >> test;
  vector<int> test2 = a.split(test, ',');
  int sum;
  cin >> sum;
  cout << a.minWindow(test2, sum) << endl;
  return 0;
}
