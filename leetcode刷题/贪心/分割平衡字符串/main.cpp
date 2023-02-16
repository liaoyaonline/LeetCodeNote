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
    stack<char> st;
    int sum = 0;
    char flag = s[0];
    for (int i = 0; i < s.size(); i++) {
      if (st.empty()) {
        st.push(s[i]);
        flag = s[i];
        continue;
      } else {
        if (s[i] == flag)
          st.push(s[i]);
        else {
          st.pop();
          if (st.empty()) sum++;
        }
      }
    }
    return sum;
  }
};
int main() {
  Solution a;
  string test = "RLRRRLLRLL";
  cout << a.minWindow(test) << endl;
  return 0;
}
