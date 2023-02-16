/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() vector<string> s = split(str,'/')####
 */
#include <stdio.h>

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
  string simplifyPath(string path) {
    auto split = [](const string& s, char delim) -> vector<string> {
      vector<string> ans;
      string cur;
      for (char ch : s) {
        if (ch == delim) {
          ans.push_back(move(cur));
          cur.clear();
        } else {
          cur += ch;
        }
      }
      ans.push_back(move(cur));
      return ans;
    };
    stack<string> name;
    string result;
    vector<string> tempname = split(path, '/');
    for (int i = 0; i < tempname.size(); i++) {
      string tempstr = tempname[i];
      if (tempstr.empty()) continue;
      if (tempstr.size() == 1 && tempstr[0] == '.') continue;
      if (tempstr.size() == 2 && tempstr[0] == '.' && tempstr[1] == '.') {
        if (!name.empty()) name.pop();
        continue;
      }
      name.push(tempstr);
    }
    if (name.empty()) return "/";
    while (!name.empty()) {
      string tempstr = name.top();
      result = '/' + tempstr + result;
      name.pop();
    }
    return result;
  }
};
int main() {
  Solution a;
  string strs;
  cin >> strs;
  cout << a.simplifyPath(strs) << endl;
  return 0;
}
