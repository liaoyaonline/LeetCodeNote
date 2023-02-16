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
  int minWindow(string str1, string str2) {
    if (str1.size() > str2.size()) return -1;
    vector<int> hashmap(27, 0);
    for (int i = 0; i < str1.size(); i++) {
      int tempindex = str1[i] - 'a';
      hashmap[tempindex]++;
    }
    for (int i = 0; i < str2.size(); i++) {
      int tempnum = str2[i] - 'a';
      if (hashmap[tempnum] != 0) {
        int flag = 0;
        string tempstr = str2.substr(i, str1.size());
        vector<int> tempmap(27, 0);
        for (int j = 0; j < tempstr.size(); j++) {
          int tempindex = tempstr[j] - 'a';
          if (hashmap[tempindex] == 0) {
            flag = 1;
            break;
          }
          tempmap[tempindex]++;
          if (tempmap[tempindex] > hashmap[tempindex]) {
            flag = 1;
            break;
          }
        }
        if (flag == 0) return i;
      }
    }
    return -1;
  }
};
int main() {
  Solution a;
  string test1 = "abc";
  string test2 = "efghicaaiii";
  cout << a.minWindow(test1, test2) << endl;
  return 0;
}
