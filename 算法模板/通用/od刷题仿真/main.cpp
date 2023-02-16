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
  vector<vector<int>> minWindow(int n, int m) {
    int nums = min(n / 2, m);
    map<int, int> easyhash;
    map<int, int> hardhash;
    vector<vector<int>> res(nums + 1, vector<int>(3, 0));
    for (int i = 1; i <= nums; i++) {
      int easynum = 0;
      int hardnum = 0;
      vector<int> tempres;
      while (easynum < 2) {
        int ans = rand() % n + 1;
        if (easyhash[ans] != 1) {
          easynum++;
          easyhash[ans] = 1;
          tempres.push_back(ans);
        }
      }
      while (hardnum < 1) {
        int ans = rand() % m + 1;
        if (hardhash[ans] != 1) {
          hardnum++;
          hardhash[ans] = 1;
          tempres.push_back(ans);
        }
      }
      res[i] = tempres;
    }
    return res;
  }
};
int main() {
  char str[50];
  time_t now = time(NULL);
  Solution a;
  vector<vector<int>> res = a.minWindow(108, 61);
  for (int i = 0; i + 2 < res.size(); i = i + 2) {
    if (i > 0) now += 86400;
    tm* t = localtime(&now);
    cout << "**" << t->tm_mon + 1 << "月" << t->tm_mday << "日刷题**" << endl;
    cout << "上午 9:30-12:00" << endl;
    cout << "简单" << endl;
    cout << "- [ ] " << res[i][0] << endl;
    cout << "- [ ] " << res[i][1] << endl << endl;
    cout << "中等" << endl;
    cout << "- [ ] " << res[i][2] << endl;
    cout << endl;
    cout << "晚上 9:30-12:00" << endl;
    cout << "简单" << endl;
    cout << "- [ ] " << res[i + 1][0] << endl;
    cout << "- [ ] " << res[i + 1][1] << endl << endl;
    cout << "中等" << endl;
    cout << "- [ ] " << res[i + 1][2] << endl;
    cout << endl;
  }
  return 0;
}
