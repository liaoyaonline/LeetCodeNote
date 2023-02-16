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
    int Mt = 0;
    int Pt = 0;
    int Gt = 0;
    vector<int> cur(3, 0);
    vector<int> flag(3, 0);
    for (int i = 0; i < garbage.size(); i++) {
      if (i > 0) {
        cur[0] += travel[i - 1];
        cur[1] += travel[i - 1];
        cur[2] += travel[i - 1];
      }
      for (int j = 0; j < garbage[i].size(); j++) {
        if (garbage[i][j] == 'M') {
          cur[0]++;
          flag[0] = 1;
        }
        if (garbage[i][j] == 'P') {
          cur[1]++;
          flag[1] = 1;
        }
        if (garbage[i][j] == 'G') {
          cur[2]++;
          flag[2] = 1;
        }
      }
      if (flag[0] == 1) {
        Mt += cur[0];
        cur[0] = 0;
        flag[0] = 0;
      }
      if (flag[1] == 1) {
        Pt += cur[1];
        cur[1] = 0;
        flag[1] = 0;
      }
      if (flag[2] == 1) {
        Gt += cur[2];
        cur[2] = 0;
        flag[2] = 0;
      }
    }
    return Mt + Pt + Gt;
  }
};
int main() {
  Solution a;
  vector<string> test1{"MMM", "PGM", "GP"};
  vector<int> test2{3, 10};
  cout << a.minWindow(test1, test2) << endl;
  return 0;
}
