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
bool cmp(vector<int> v, vector<int> u) {
  return v[0] != u[0] ? v[0] > u[0] : v[1] < u[1];
}
class Solution {
 public:
  vector<vector<int>> minWindow(vector<vector<int>>& people) {
    vector<vector<int>> input = people;
    sort(input.begin(), input.end(), cmp);
    vector<vector<int>> result;
    for (int i = 0; i < input.size(); i++) {
      vector<int> temp = input[i];
      result.insert(result.begin() + temp[1], temp);
    }
    return result;
  }
};
int main() {
  Solution a;
  vector<vector<int>> test{{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
  vector<vector<int>> result = a.minWindow(test);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i][0] << "," << result[i][1] << endl;
  }
  return 0;
}
