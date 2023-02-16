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
  bool isPalindrome(string s) {
    string result;
    if (s.empty()) return true;
    for (int i = 0; i < s.size(); i++) {
      char tempchar;
      if (s[i] <= 'z' && s[i] >= 'a') result.push_back(s[i]);
      if (s[i] <= 'Z' && s[i] >= 'A') {
        tempchar = 'a' + (s[i] - 'A');
        result.push_back(tempchar);
      }
      if (s[i] <= '9' && s[i] >= '0') result.push_back(s[i]);
    }
    for (int i = 0; i < (result.size() / 2); i++) {
      if (result[i] != result[result.size() - i - 1]) return false;
    }
    return true;
  }
};
int main() {
  Solution a;
  string strs;
  cin >> strs;
  cout << a.isPalindrome(strs) << endl;
  return 0;
}
