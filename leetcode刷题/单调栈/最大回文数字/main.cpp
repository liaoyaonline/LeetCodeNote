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
bool cmp(char num1, char num2) { return num1 > num2; }
class Solution {
 public:
  string minWindow(string num) {
    string strs = num;
    sort(strs.begin(), strs.end(), cmp);
    stack<char> st;
    string doublenum = "";
    char singnum = 'k';
    st.push(strs[0]);
    for (int i = 1; i < strs.size(); i++) {
      if (!st.empty() && strs[i] == st.top()) {
        doublenum.push_back(strs[i]);
        st.pop();
      } else
        st.push(strs[i]);
    }
    while (!st.empty()) {
      singnum = st.top();
      st.pop();
    }
    string result = "";
    if ((doublenum.empty() || doublenum[0] == '0') && singnum != 'k') {
      result.push_back(singnum);
      return result;
    }
    if ((doublenum.empty() || doublenum[0] == '0') && singnum == 'k') {
      result = "0";
      return result;
    }
    result = doublenum;
    if (singnum != 'k') result.push_back(singnum);
    for (int i = doublenum.size() - 1; i >= 0; i--)
      result.push_back(doublenum[i]);
    return result;
  }
};
int main() {
  Solution a;
  string test = "00";
  cout << a.minWindow(test) << endl;
  return 0;
}
