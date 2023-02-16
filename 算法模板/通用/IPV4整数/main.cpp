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
  vector<int> split(string s, char ch) {
    vector<int> res;
    if (s.empty()) return res;
    string tempstr = "";
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ch) {
        if (tempstr.empty()) continue;
        int tempnum = atoi(tempstr.c_str());
        res.push_back(tempnum);
        tempstr = "";
        continue;
      }
      tempstr.push_back(s[i]);
    }
    if (!tempstr.empty()) {
      int tempnum2 = atoi(tempstr.c_str());
      res.push_back(tempnum2);
    }
    return res;
  }
  int minWindow(vector<int> nums) {
    if (nums.size() != 4) {
      cout << "invalid IP" << endl;
      return -1;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] < 0 || nums[i] > 128) {
        cout << "invalid IP" << endl;
        return -1;
      }
    }
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      int offset = 8 * (3 - i);
      sum += nums[i] << offset;
    }
    cout << sum << endl;
    return 0;
  }
};
int main() {
  Solution a;
  string teststr;
  cin >> teststr;
  vector<int> test = a.split(teststr, '#');
  a.minWindow(test);
  return 0;
}
