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
bool cmp(vector<int> u, vector<int> v) { return u[1] < v[1]; }
class Solution {
 public:
  int minWindow(vector<int> nums, int maxnum, int k) {
    int num = 0;
    for (int i = 0; i <= maxnum; i++) {
      if (nums[i] != 0) {
        num++;
        i = i + k;
      }
    }
    return num;
  }
};
int main() {
  Solution a;
  int n;
  int k;
  cin >> n;
  cin >> k;
  int maxnum;
  vector<int> test(2000, 0);
  for (int i = 0; i < n; i++) {
    int start;
    int times;
    cin >> start;
    cin >> times;
    int tem = times + start;
    maxnum = max(tem, maxnum);
    test[tem]++;
  }
  cout << a.minWindow(test, maxnum, k) << endl;
  return 0;
}
