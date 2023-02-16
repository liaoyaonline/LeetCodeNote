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
  vector<int> minWindow(vector<int> nums) {
    int sum = 0;
    int n = nums.size();
    vector<int> res(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++) sum += nums[i];
    for (int i = 1; i < 200 && sum > 0; i++) {
      if (i % 7 == 0 || i % 10 == 7 || (i / 10) % 10 == 7) {
        sum--;
        int index = ((i % n + n) - 1) % n;
        res[index]++;
      }
    }
    return res;
  }
};
int main() {
  Solution a;
  string tempstr;
  getline(cin, tempstr);
  vector<int> test = a.split(tempstr, ' ');
  vector<int> res = a.minWindow(test);
  for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
  cout << endl;
  return 0;
}
