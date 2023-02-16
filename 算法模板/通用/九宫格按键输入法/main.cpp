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
  string minWindow(string s) {
    string res;
    int flagsysteam = 0;
    map<char, string> hashmap;
    hashmap['0'] = " ";
    hashmap['1'] = ",.";
    hashmap['2'] = "abc";
    hashmap['3'] = "def";
    hashmap['4'] = "ghi";
    hashmap['5'] = "jkl";
    hashmap['6'] = "mno";
    hashmap['7'] = "pqrs";
    hashmap['8'] = "tuv";
    hashmap['9'] = "wxyz";
    for (int i = 0; i < s.size(); i++) {
      if (s[i] <= '9' && s[i] >= '0') {
        if (flagsysteam == 0) {
          res.push_back(s[i]);
          continue;
        }
        if (flagsysteam == 1) {
          int r = i;
          char Key = s[i];
          string tempstr = hashmap[Key];
          while (r < s.size() && s[r] == s[i]) r++;
          int index =
              (r - i - 1) %
              (tempstr.size());  //长度为r - i因为字符串里是0起步需要再-1
          res.push_back(tempstr[index]);
          i = r - 1;  //将i 移动到r因为continue后会自动++，所以先-1
          continue;
        }
      }
      if (s[i] == '#') {
        flagsysteam = (flagsysteam + 1) % 2;
        continue;
      }
      if (s[i] == '/') {
        continue;
      }
    }
    return res;
  }
};
int main() {
  Solution a;
  string test;
  cin >> test;
  cout << a.minWindow(test) << endl;
  return 0;
}
