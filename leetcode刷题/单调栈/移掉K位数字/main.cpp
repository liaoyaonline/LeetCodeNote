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
  string removeKdigits(string num, int k) {
    vector<char> st;
    string result = "";
    for (int i = 0; i < num.size(); i++) {
      while (!st.empty() && num[i] < st.back() && k) {
        st.pop_back();
        k--;
      }
      st.push_back(num[i]);
    }
    for (; k > 0; k--) st.pop_back();
    bool isleadzero = true;
    for (int i = 0; i < st.size(); i++) {
      if (isleadzero && st[i] == '0') {
        continue;
      }
      isleadzero = false;
      result += st[i];
    }
    return result == "" ? "0" : result;
  }
};
int main() {
  Solution a;
  string test = "1000";
  cout << a.removeKdigits(test, 3) << endl;
  return 0;
}
