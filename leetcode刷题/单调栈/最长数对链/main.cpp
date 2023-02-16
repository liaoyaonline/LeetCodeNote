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
bool cmp(vector<int> u, vector<int> v) {
  return u[1] != v[1] ? u[1] < v[1] : u[0] < v[0];
}
class Solution {
 public:
  int minWindow(vector<vector<int>>& pairs) {
    sort(pairs.begin(), pairs.end(), cmp);
    stack<vector<int>> st;
    st.push(pairs[0]);
    for (int i = 0; i < pairs.size(); i++) {
      if (pairs[i][0] > st.top()[1]) st.push(pairs[i]);
    }
    return st.size();
  }
};
int main() {
  Solution a;
  vector<vector<int>> test{{1, 2}, {2, 3}, {3, 4}};
  cout << a.minWindow(test) << endl;
  return 0;
}
