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
  map<int, int> hashmap;
  void dfs(int num, int currnum, int N, vector<int> flag) {
    if (currnum > N) {
      hashmap[num] = 1;
      return;
    }
    dfs(num ^ flag[0], currnum + 1, N, flag);
    dfs(num ^ flag[1], currnum + 1, N, flag);
    dfs(num ^ flag[2], currnum + 1, N, flag);
    dfs(num ^ flag[3], currnum + 1, N, flag);
  }
  int minWindow(int n, int presses) {
    vector<int> flag(4, 0);
    int num = pow(2, n) - 1;
    flag[0] = num;
    int tempnum = 0;
    for (int i = 0; i < n; i = i + 2) {
      tempnum += pow(2, i);
    }
    flag[1] = tempnum;
    flag[2] = num ^ tempnum;
    tempnum = 0;
    for (int i = 0; i < n; i = i + 3) {
      tempnum += pow(2, i);
    }
    flag[3] = tempnum;
    dfs(num, 1, presses, flag);
    return hashmap.size();
  }
};
int main() {
  Solution a;
  cout << a.minWindow(1, 1) << endl;
  return 0;
}
