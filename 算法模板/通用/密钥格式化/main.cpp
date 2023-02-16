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
      if (s[i] == ',') {
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
  string minWindow(string s, int K) {
    int len;
    int start = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '-') {
        start = i;
        break;
      }
    }
    string res = s.substr(0, start);
    string remain = "";
    for (int i = start; i < s.size(); i++) {
      if (s[i] <= 'z' && s[i] >= 'a') {
        int tempindex = s[i] - 'a';
        char tempchar = 'A' + tempindex;
        remain.push_back(tempchar);
        len++;
        if (len % K == 0) {
          remain.push_back('-');
        }
        continue;
      }
      if (s[i] <= 'Z' && s[i] >= 'A') {
        remain.push_back(s[i]);
        len++;
        if (len % K == 0) remain.push_back('-');
        continue;
      }
      if (s[i] <= '9' && s[i] >= '0') {
        remain.push_back(s[i]);
        len++;
        if (len % K == 0) remain.push_back('-');
        continue;
      }
      if (s[i] == '-') {
        continue;
      }
    }
    if (len % K == 0) remain.pop_back();
    return res + "-" + remain;
  }
};
int main() {
  Solution a;
  string test = "2-5g-3-J";
  cout << a.minWindow(test, 2) << endl;
  return 0;
}
