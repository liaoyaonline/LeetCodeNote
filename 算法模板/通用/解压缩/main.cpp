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
  void getdata(string& frontstr, int& nums, string s, int start) {
    int i = 0;
    int j = 0;
    string tempnum;
    for (i = start - 1; i >= 0; i--) {
      if (s[i] == ']' || s[i] == '[') {
        break;
      }
    }
    for (j = i + 1; j < s.size(); j++) {
      if (s[j] < 'a' || s[j] > 'z') {
        break;
      }
      frontstr.push_back(s[j]);
    }
    for (int l = j; l < s.size(); l++) {
      if (s[l] == '[') {
        int temp = atoi(tempnum.c_str());
        nums = temp;
        break;
      }
      tempnum.push_back(s[l]);
    }
  }
  string minWindow(string s) {
    stack<int> st;
    string result = "";
    string res = "";
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '[') {
        st.push(i);
        continue;
      }
      if (s[i] == ']') {  //遇到]开始操作
        int start = st.top();
        st.pop();
        int end = i;
        string frontstr;
        int nums;
        getdata(frontstr, nums, s, start);  //提取[前面的数字，字符串
        if (res.empty()) {  //如果是最内层，需要手动提取
          res = s.substr(start + 1, end - start - 1);
        }
        string tempres = "";
        for (int i = 0; i < nums; i++) {
          tempres += res;
        }
        res = frontstr + tempres;
        if (st.empty()) {  //栈道为空，说明一个内嵌[]结束，需要将res清空，来迎接下一个内嵌
          result += res;
          res = "";
        }
      }
    }
    return result;
  }
};
int main() {
  Solution a;
  string test;
  cin >> test;
  cout << a.minWindow(test) << endl;
  return 0;
}
