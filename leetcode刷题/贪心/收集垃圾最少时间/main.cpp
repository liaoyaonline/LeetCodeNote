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
  int minWindow(vector<string>& garbage, vector<int>& travel) {
    int res = 0, mnm = 0, mnp = 0, mng = 0;
    for (int i = 0; i < garbage.size(); i++) {
      res += garbage[i].size();
      for (auto it : garbage[i]) {
        if (it == 'M') mnm = i;
        if (it == 'P') mnp = i;
        if (it == 'G') mng = i;
      }
    }
    for (int i = 0; i < mnm; i++) res += travel[i];
    for (int i = 0; i < mnp; i++) res += travel[i];
    for (int i = 0; i < mng; i++) res += travel[i];
    return res;
  }
};
int main() {
  Solution a;
  vector<string> test1{"MMM", "PGM", "GP"};
  vector<int> test2{3, 10};
  cout << a.minWindow(test1, test2) << endl;
  return 0;
}
