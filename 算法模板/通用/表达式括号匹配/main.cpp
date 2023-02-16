/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin() bool cmp(const word &num1, const word &num2) {
  return num1.value != num2.value ? num1.value > num2.value: num1.name <
 num2.name;} v.insert(v.begin()+3,1);map.containsKey(num) s.substr(i,2)####
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
  int minWindow(string s) {
    int nums = 0;
    string tempstr = "";
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(' || s[i] == ')') tempstr.push_back(s[i]);
    }
    for (int i = 0; i < tempstr.size(); i++) {
      if (tempstr[i] == '(') {
        st.push(tempstr[i]);
      }
      if (tempstr[i] == ')') {
        if (st.top() == '(') {
          nums++;
          st.pop();
        } else {
          return -1;
        }
      }
    }
    return st.empty() ? nums : -1;
  }
};
int main() {
  Solution a;
  string test;
  cin >> test;
  cout << a.minWindow(test) << endl;
  return 0;
}
