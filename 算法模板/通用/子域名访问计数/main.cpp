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
  vector<string> minWindow(vector<string>& cpdomains) {
    map<string, int> hashmap;
    vector<string> res;
    string tempstr = "";
    for (int i = 0; i < cpdomains.size(); i++) {
      int tempindex = 0;
      for (int j = 0; j < cpdomains[i].size(); j++) {
        if (cpdomains[i][j] == ' ') {
          tempindex = j;
          break;
        }
      }
      tempstr = cpdomains[i].substr(0, tempindex);
      int tempnum = atoi(tempstr.c_str());
      tempstr = cpdomains[i].substr(tempindex + 1);
      string temphttp = "";
      for (int j = tempstr.size() - 1; j >= 0; j--) {
        if (tempstr[j] == '.') {
          temphttp = tempstr.substr(j + 1);
          hashmap[temphttp] += tempnum;
        }
      }
      temphttp = tempstr;
      hashmap[temphttp] += tempnum;
    }
    for (auto it = hashmap.begin(); it != hashmap.end(); it++) {
      int tempnum = it->second;
      string tempres = to_string(tempnum);
      tempres = tempres + " " + it->first;
      res.push_back(tempres);
    }
    return res;
  }
};
int main() {
  Solution a;
  vector<string> test = {"9001 discuss.leetcode.com"};
  vector<string> res = a.minWindow(test);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << endl;
  }
  return 0;
}
