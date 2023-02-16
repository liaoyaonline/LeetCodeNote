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
class LUPrefix {
 public:
  vector<int> prefix;
  int currmax;
  LUPrefix(int n) {
    currmax = 0;
    for (int i = 0; i <= n; i++) prefix.push_back(0);
  }
  void upload(int video) { prefix[video] = 1; }
  int longest() {
    for (int i = currmax + 1; i < prefix.size(); i++) {
      if (prefix[i] == 0) {
        return currmax;
      }
      currmax = i;
    }
    return currmax;
  }
};
int main() {
  LUPrefix a(4);
  cout << a.longest() << endl;
  a.upload(1);
  cout << a.longest() << endl;
  a.upload(4);
  cout << a.longest() << endl;
  return 0;
}
