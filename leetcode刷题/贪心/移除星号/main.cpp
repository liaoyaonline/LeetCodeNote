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
  string minWindow(string s) {
    string res = "";
    for (int i = 0; i < s.size(); i++) {
      if (!res.empty() && s[i] == '*') {
        res.pop_back();
        continue;
      }
      res.push_back(s[i]);
    }
    return res;
  }
};
int main() {
  Solution a;
  string test = "erase*****";
  cout << a.minWindow(test) << endl;
  return 0;
}
