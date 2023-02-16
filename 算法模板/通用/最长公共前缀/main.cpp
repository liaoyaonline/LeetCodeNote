/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin() bool cmp(const word &num1, const word &num2) {
  return num1.value != num2.value ? num1.value > num2.value: num1.name <
 num2.name;} v.insert(v.begin()+3,1);map.containsKey(num) s.substr(i,2)####
string b= to_string(int a); int a =
atoi(b.c_str());d.emplace(d.begin()+1,4)在0后，1前面插入4
d.erase(d.begin()+1);删除1坐标上的数据*/
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
  string minWindow(vector<string>& strs) {
    string res = "";
    for (int i = 0; i < strs[0].size(); i++) {
      char flag = strs[0][i];
      for (int j = 0; j < strs.size(); j++) {
        if (i >= strs[j].size() || strs[j][i] != flag) {
          return res;
        }
      }
      res.push_back(flag);
    }
    return res;
  }
};
int main() {
  Solution a;
  vector<string> test{"flower", "flow", "flight"};
  cout << a.minWindow(test) << endl;
  return 0;
}
