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
  vector<string> sqit(string s, char ch) {
    vector<string> res;
    if (s.empty()) return res;
    string tempstr = "";
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ch) {
        res.push_back(tempstr);
        tempstr = "";
        continue;
      }
      tempstr.push_back(s[i]);
    }
    res.push_back(tempstr);
    return res;
  }
  string minWindow(string s, int start, int end) {
    vector<string> word = sqit(s, ' ');
    string res = "";
    for (int i = start, j = end; i < j; i++, j--) swap(word[i], word[j]);
    for (int i = 0; i < word.size(); i++) {
      res += word[i];
      res += " ";
    }
    res.pop_back();
    return res;
  }
};
int main() {
  Solution a;
  string test;
  int start;
  int end;
  getline(cin, test);
  cin >> start;
  cin >> end;
  cout << a.minWindow(test, start, end) << endl;
  return 0;
}
