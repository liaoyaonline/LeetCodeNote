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
bool cmp(vector<int> u, vector<int> v) {
  return u[0] != v[0] ? u[0] < v[0] : u[1] > v[1];
}
class Solution {
 public:
  vector<vector<int>> split(string s) {
    vector<vector<int>> res;
    if (s.empty()) return res;
    int n = s.size();
    string tempstr = s.substr(1, n - 2);
    if (tempstr.empty()) return res;
    n = tempstr.size();
    int start = 0;
    for (int i = 0; i < n; i++) {
      if (tempstr[i] == '[') {
        start = i;
      }
      if (tempstr[i] == ']') {
        string tempsubstr = tempstr.substr(start + 1, i - start - 1);
        int inordindex = 0;
        for (int i = 0; i < tempsubstr.size(); i++) {
          if (tempsubstr[i] == ',') {
            inordindex = i;
            break;
          }
        }
        vector<int> temp(2, 0);
        string tempnumstr = tempsubstr.substr(0, inordindex);
        int tempnum = atoi(tempnumstr.c_str());
        temp[0] = tempnum;
        tempnumstr = tempsubstr.substr(inordindex + 1);
        tempnum = atoi(tempnumstr.c_str());
        temp[1] = tempnum;
        res.push_back(temp);
      }
    }
    return res;
  }
  int minWindow(vector<vector<int>> nums) {
    if (nums.empty()) return 0;
    int maxlen = 1;
    stack<vector<int>> st;
    sort(nums.begin(), nums.end(), cmp);
    st.push(nums[0]);
    vector<int> dp(nums.size() + 1, 1);
    for (int i = 1; i < nums.size(); i++) {
      for (int j = 0; j < i; j++)
        if (nums[i][1] > nums[j][1]) {
          dp[i] = max(dp[i], dp[j] + 1);
          maxlen = max(dp[i], maxlen);
        }
    }
    return maxlen;
  }
};
int main() {
  Solution a;
  string teststr;
  cin >> teststr;
  vector<vector<int>> test = a.split(teststr);
  cout << a.minWindow(test) << endl;
  return 0;
}
