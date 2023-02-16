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
  int minWindow(string& s, int k) {
    vector<int> flag(2, 0);
    vector<int> hashmap(60, -1);
    if (k >= s.size()) flag[0] = 1;
    for (int i = 0; i < s.size(); i++) {
      int tempindex = s[i] - 'A';
      if (hashmap[tempindex] > -1) {
        flag[1] = 1;
        continue;
      }
      hashmap[tempindex] = i;
    }
    sort(s.begin(), s.end());
    if (flag[0] == 1) {
      int tempindex = s[s.size() - 1] - 'A';
      return hashmap[tempindex];
    }
    if (flag[1] == 1) {
      int tempindex = s[0] - 'A';
      return hashmap[tempindex];
    }
    int tempindex = s[k - 1] - 'A';
    return hashmap[tempindex];
  }
};
int main() {
  Solution a;
  string test;
  cin >> test;
  int k;
  cin >> k;
  cout << a.minWindow(test, k) << endl;
  return 0;
}
