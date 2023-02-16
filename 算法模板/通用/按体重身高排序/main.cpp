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
bool cmp(vector<int> u, vector<int> v) {
  return u[1] != v[1] ? u[1] < v[1] : u[2] < v[2];
}
class Solution {
 public:
  vector<int> minWindow(vector<vector<int>> student) {
    sort(student.begin(), student.end(), cmp);
    vector<int> res(student.size(), 0);
    for (int i = 0; i < student.size(); i++) {
      res[i] = student[i][0];
    }
    return res;
  }
};
int main() {
  Solution a;
  int N;
  cin >> N;
  vector<vector<int>> test(N, vector<int>(3, 0));
  for (int i = 0; i < N; i++) {
    test[i][0] = i + 1;
    cin >> test[i][1];
  }
  for (int i = 0; i < N; i++) {
    cin >> test[i][2];
  }
  vector<int> res = a.minWindow(test);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}
