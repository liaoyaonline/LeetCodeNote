/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin() bool cmp(const word &num1, const word &num2) {
  return num1.value != num2.value ? num1.value > num2.value: num1.name <
 num2.name;} v.insert(v.begin()+3,1);map.containsKey(num) s.substr(i,2)####
string b= to_string(int a); int a = atoi(b.c_str());*/
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
  vector<int> minWindow(vector<int>& nums, int firstnum, int numlen) {
    int k = 1;
    int curcount = firstnum;
    int len = numlen;
    vector<int> res;
    for (int i = 0; res.size() != numlen; i = (i + 1) % len) {
      if (nums[i] > 0) {
        curcount--;
        if (curcount == 0) {
          curcount = nums[i];
          res.push_back(nums[i]);
          nums[i] = 0;
        }
      }
    }
    return res;
  }
};
int main() {
  Solution a;
  vector<int> test{3, 1, 2, 4, 6, 7, 8};
  int len = test.size();
  vector<int> result = a.minWindow(test, 7, len);
  for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
  cout << endl;
  return 0;
}
