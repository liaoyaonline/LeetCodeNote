#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  bool isValid(string s) {
    stack<char> braces;
    for (int i = 0; i < s.size(); i++) {
      switch (s[i]) {
        case '(':
        case '[':
        case '{':
          braces.push(s[i]);
          break;
        case ']':
          if (braces.empty() || braces.top() != '[') {
            return false;
          } else {
            braces.pop();
          }
          break;
        case ')':
          if (braces.empty() || braces.top() != '(')
            return false;
          else
            braces.pop();
          break;
        case '}':
          if (braces.empty() || braces.top() != '{')
            return false;
          else
            braces.pop();
          break;
      }
    }
    if (!braces.empty()) return false;
    return true;
  }
};
int main() {
  Solution a;
  string str;
  cin >> str;
  cout << a.isValid(str) << endl;
  return 0;
}
