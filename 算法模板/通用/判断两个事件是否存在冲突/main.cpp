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
  int split(string s) {
    string tempstr1 = s.substr(0, 2);
    string tempstr2 = s.substr(3, 2);
    int tempnum1 = atoi(tempstr1.c_str());
    int tempnum2 = atoi(tempstr2.c_str());
    int res = tempnum1 * 60 + tempnum2;
    return res;
  }
  bool minWindow(vector<string>& event1, vector<string>& event2) {
    int start = split(event1[0]);
    int end = split(event1[1]);
    int test1 = split(event2[0]);
    int test2 = split(event2[1]);
    if (test1 <= start && test2 >= end) return true;
    if ((test1 <= end && test1 >= start) || (test2 <= end && test2 >= start))
      return true;
    return false;
  }
};
int main() {
  Solution a;
  vector<string> test1{"15:19", "17:56"};
  vector<string> test2{"14:11", "20:02"};
  cout << a.minWindow(test1, test2) << endl;
  return 0;
}
