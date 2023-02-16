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
  vector<int> split(string s, char ch) {
    vector<int> res;
    if (s.empty()) return res;
    string tempstr = "";
    int flag = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ch) {
        if (flag < 1) {
          flag++;
          tempstr = "";
          continue;
        }
        int tempnum = atoi(tempstr.c_str());
        res.push_back(tempnum);
        tempstr = "";
        continue;
      }
      tempstr.push_back(s[i]);
    }
    int tempnum2 = atoi(tempstr.c_str());
    res.push_back(tempnum2);
    return res;
  }
  string minWindow(string s) {
    stack<string> st;
    stack<int> stindex;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        string tempstr;
        tempstr.push_back(s[i + 1]);
        st.push(tempstr);
        stindex.push(i);
        continue;
      }
      if (s[i] == ')') {
        string flag = st.top();
        if (flag[0] < '0' || flag[0] > '9') {
          int index = stindex.top();
          int len = i - index;
          string tempstr = s.substr(index, len);
          string op = st.top();
          st.pop();
          vector<int> nums = split(tempstr, ' ');
          int tempfirstnum = nums[0];
          int tempsecondnum = nums[1];
          int intresult = 0;
          string strresult = "";
          switch (op[0]) {
            case 'a':
              intresult = tempfirstnum + tempsecondnum;
              break;
            case 's':
              intresult = tempfirstnum - tempsecondnum;
              break;
            case 'm':
              intresult = tempfirstnum * tempsecondnum;
              break;
            case 'd':
              if (tempsecondnum == 0) return "error";
              intresult = tempfirstnum / tempsecondnum;
              break;
          }
          strresult = to_string(intresult);
          st.push(strresult);
        } else {
          string secondnum = flag;
          st.pop();
          string firstnum = st.top();
          st.pop();
          string op = st.top();
          st.pop();
          int tempfirstnum = atoi(firstnum.c_str());
          int tempsecondnum = atoi(secondnum.c_str());
          int intresult = 0;
          string strresult = "";
          switch (op[0]) {
            case 'a':
              intresult = tempfirstnum + tempsecondnum;
              break;
            case 's':
              intresult = tempfirstnum - tempsecondnum;
              break;
            case 'm':
              intresult = tempfirstnum * tempsecondnum;
              break;
            case 'd':
              if (tempsecondnum == 0) return "error";
              intresult = tempfirstnum / tempsecondnum;
              break;
          }
          strresult = to_string(intresult);
          st.push(strresult);
        }
        stindex.pop();
        continue;
      }
    }
    return st.top();
  }
};
int main() {
  Solution a;
  string test = "(sub(mul 2 4)(sub(mul 2 4)(div 9 3)))";
  cout << a.minWindow(test) << endl;
  return 0;
}
