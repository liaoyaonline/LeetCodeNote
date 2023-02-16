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
        int tempnum = atoi(tempstr.c_str());
        res.push_back(tempnum);
        tempstr = "";
        continue;
      }
      tempstr.push_back(s[i]);
    }
    int tempnum2 = atoi(tempstr.c_str());
    res.push_back(tempnum2);
    return res;
  }
  int minWindow(vector<int>& nums) {
    vector<int> result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      int flag = 0;
      for (int j = 0; j < result.size(); j++) {
        if (nums[i] % result[j] == 0) {
          flag = 1;
          break;
        }
      }
      if (flag == 0) {
        result.push_back(nums[i]);
      }
    }
    return result.size();
  }
};
int main() {
  Solution a;
  vector<int> test{2, 3, 5, 8, 9, 4, 6};
  cout << a.minWindow(test) << endl;
  return 0;
}
