/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end()####
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
  bool isValid(string s) {
    stack<char> strs;
    for (int i = 0; i < s.size(); i++) {
      switch (s[i]) {
        case '(':
          strs.push(s[i]);
          break;
        case '{':
          strs.push(s[i]);
          break;
        case '[':
          strs.push(s[i]);
          break;
        case ')':
          if (strs.empty() || '(' != strs.top()) return false;
          strs.pop();
          break;
        case ']':
          if (strs.empty() || '[' != strs.top()) return false;
          strs.pop();
          break;
        case '}':
          if (strs.empty() || '{' != strs.top()) return false;
          strs.pop();
          break;
        default:
          break;
      }
    }
    if (!strs.empty()) return false;
    return true;
  }
};
int main() {
  Solution a;
  string strs;
  cin >> strs;
  cout << a.isValid(strs) << endl;
  return 0;
}
