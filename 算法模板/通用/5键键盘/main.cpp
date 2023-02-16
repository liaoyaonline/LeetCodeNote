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
  int minWindow(string s) {
    string test = "";
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ') continue;
      test.push_back(s[i]);
    }
    int n = 0;
    int buffn = 0;
    int flag = 0;
    for (int i = 0; i < test.size(); i++) {
      switch (test[i]) {
        case '1':
          if (flag == 0) {
            n++;
            break;
          }
          if (flag == 1) {
            n = 0;
            n++;
            break;
          }
        case '2':
          if (flag == 1) {
            buffn = n;
          }
          break;
        case '3':
          if (flag == 1) {
            buffn = n;
            n = 0;
            flag == 0;
          }
          break;
        case '4':
          if (flag == 1) {
            n = 0;
            n += buffn;
            flag = 0;
            break;
          }
          if (flag == 0) {
            n += buffn;
            break;
          }
        case '5':
          if (n != 0) {
            flag = 1;
          }
          break;
      }
    }
    return n;
  }
};
int main() {
  Solution a;
  string test;
  getline(cin, test);
  cout << a.minWindow(test) << endl;
  return 0;
}
