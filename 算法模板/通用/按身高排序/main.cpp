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
bool cmp(vector<int> u, vector<int> v) { return u[0] > v[0]; }
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
  vector<string> minWindow(vector<string>& names, vector<int>& heights) {
    int n = heights.size();
    vector<vector<int>> hedp(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++) {
      hedp[i][0] = heights[i];
      hedp[i][1] = i;
    }
    sort(hedp.begin(), hedp.end(),
         [](vector<int> u, vector<int> v) { return u[0] > v[0]; });
    vector<string> res(n);
    for (int i = 0; i < n; i++) {
      res[i] = names[hedp[i][1]];
    }
    return res;
  }
};
int main() {
  Solution a;
  a.minWindow();
  return 0;
}
