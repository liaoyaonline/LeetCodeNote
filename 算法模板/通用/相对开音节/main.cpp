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
  vector<string> split(string s, char ch) {
    vector<string> res;
    if (s.empty()) return res;
    string tempstr = "";
    int flag = 0;
    for (int i = 0; i < s.size(); i++) {
      if ((s[i] < 'a' || s[i] > 'z') && s[i] != ch) flag = 1;
      if (s[i] == ch) {
        if (flag == 0) {
          for (int j = 0; j < tempstr.size() / 2; j++)
            swap(tempstr[j], tempstr[tempstr.size() - 1 - j]);
        }
        res.push_back(tempstr);
        tempstr = "";
        flag = 0;
        continue;
      }
      tempstr.push_back(s[i]);
    }
    if (flag == 0) {
      for (int j = 0; j < tempstr.size() / 2; j++)
        swap(tempstr[j], tempstr[tempstr.size() - 1 - j]);
    }
    res.push_back(tempstr);
    return res;
  }
  int minWindow(vector<string> s) {
    int res = 0;
    vector<int> fuyin1(27, 0);
    vector<int> fuyin2(27, 0);
    vector<int> yuanyin(27, 0);
    vector<int> e(27, 0);
    int temp = 'a' - 'a';
    yuanyin[temp] = 1;
    temp = 'e' - 'a';
    yuanyin[temp] = 1;
    temp = 'i' - 'a';
    yuanyin[temp] = 1;
    temp = 'o' - 'a';
    yuanyin[temp] = 1;
    temp = 'u' - 'a';
    yuanyin[temp] = 1;
    for (int i = 0; i < 26; i++) {
      if (yuanyin[i] == 0) {
        fuyin1[i] = 1;
        fuyin2[i] = 1;
      }
    }
    temp = 'r' - 'a';
    fuyin2[temp] = 0;
    temp = 'e' - 'a';
    e[temp] = 1;
    for (int i = 0; i < s.size(); i++) {
      if (s[i].size() < 4) continue;
      for (int j = 0; j < s[i].size(); j++) {
        int tempindex1 = s[i][j] - 'a';
        if (s[i][j] <= 'z' && s[i][j] >= 'a' && fuyin1[tempindex1] == 1 &&
            j + 3 < s[i].size()) {
          int tempindex2 = s[i][j + 1] - 'a';
          int tempindex3 = s[i][j + 2] - 'a';
          int tempindex4 = s[i][j + 3] - 'a';
          if (tempindex2 >= 0 && tempindex2 < 26 && tempindex3 >= 0 &&
              tempindex3 < 26 && tempindex4 >= 0 && tempindex4 < 26) {
            res += (yuanyin[tempindex2] * fuyin2[tempindex3] * e[tempindex4]);
          }
        }
      }
    }
    return res;
  }
};
int main() {
  Solution a;
  string temptest;
  getline(cin, temptest);
  vector<string> test = a.split(temptest, ' ');
  for (int i = 0; i < test.size(); i++) cout << test[i] << " ";
  cout << endl;
  cout << a.minWindow(test) << endl;
  return 0;
}
