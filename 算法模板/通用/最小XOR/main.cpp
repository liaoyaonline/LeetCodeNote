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
  int minWindow(int num1, int num2) {
    int zeronum1 = 0;
    int zeronum2 = 0;
    int ret = num1;
    int flag = 1;
    while (flag) {
      if (num1 & flag) {
        zeronum1++;
      }
      flag = flag << 1;
    }
    flag = 1;
    while (flag) {
      if (num2 & flag) {
        zeronum2++;
      }
      flag = flag << 1;
    }
    if (zeronum1 > zeronum2) {
      int delnum = zeronum1 - zeronum2;
      flag = 1;
      while (flag > 0 && delnum > 0) {
        if (ret & flag) {
          ret = ret ^ flag;
          delnum--;
        }
        flag = flag << 1;
      }
      return ret;
    }
    if (zeronum1 == zeronum2) {
      return ret;
    }
    if (zeronum1 < zeronum2) {
      int addnum = zeronum2 - zeronum1;
      flag = 1;
      while (flag > 0 && addnum > 0) {
        if (!(ret & flag)) {
          ret = ret | flag;
          addnum--;
        }
        flag = flag << 1;
      }
      return ret;
    }
    return ret;
  }
};
int main() {
  Solution a;
  cout << a.minWindow(8, 75) << endl;
  return 0;
}
