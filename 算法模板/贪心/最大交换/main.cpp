/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin() bool cmp(const word &num1, const word &num2) {
  return num1.value != num2.value ? num1.value > num2.value: num1.name <
 num2.name;} v.insert(v.begin()+3,1);map.containsKey(num) s.substr(i,2)####
priority_queue<int, vector<int>, greater<>> pq;//小根堆
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
bool cmp(int u, int v) { return u > v; }
class Solution {
 public:
  int minWindow(int num) {
    if (num < 10) return num;
    vector<int> oldnum;
    while (num) {
      int a = num / 10;
      int b = num % 10;
      oldnum.push_back(b);
      num = a;
    }
    for (int i = 0; i < oldnum.size() / 2; i++)
      swap(oldnum[i], oldnum[oldnum.size() - i - 1]);
    vector<int> newnum = oldnum;
    sort(newnum.begin(), newnum.end(), [](int u, int v) { return u > v; });
    for (int i = 0; i < oldnum.size(); i++) {
      if (oldnum[i] == newnum[i]) continue;
      int index = i;
      for (int j = i; j < oldnum.size(); j++) {
        if (oldnum[j] == newnum[i]) {
          index = j;
        }
      }
      swap(oldnum[i], oldnum[index]);
      break;
    }
    int res = oldnum[0];
    for (int i = 1; i < oldnum.size(); i++) {
      res = res * 10 + oldnum[i];
    }
    return res;
  }
};
int main() {
  Solution a;
  cout << a.minWindow(1993) << endl;
  return 0;
}
