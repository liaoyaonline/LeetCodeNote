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
  int minWindow(string s) {
    stack<int> st;
    int res = 0;
    if (s.empty()) return res;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        st.push(-1);
        continue;
      }
      if (s[i] == ')') {
        if (st.top() == -1) {
          st.pop();
          st.push(1);
        } else {
          int tempsum = 0;
          while (st.top() != -1) {
            tempsum += st.top();
            st.pop();
          }
          tempsum = tempsum * 2;
          st.pop();
          st.push(tempsum);
        }
      }
    }
    if (st.size() == 1) res = st.top();
    if (st.size() > 1) {
      while (!st.empty()) {
        res += st.top();
        st.pop();
      }
    }
    return res;
  }
};
int main() {
  Solution a;
  string test = "(()(()))";
  cout << a.minWindow(test) << endl;
  return 0;
}
