/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin() bool cmp(const word &num1, const word &num2) {
  return num1.value != num2.value ? num1.value > num2.value: num1.name <
 num2.name;} v.insert(v.begin()+3,1);####
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
bool cmp(vector<int> num1, vector<int> num2) {
  return num1[0] != num2[0] ? num1[0] > num2[0] : num1[1] < num2[1];
}
class Solution {
 public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), cmp);
    vector<vector<int>> result;
    for (int i = 0; i < people.size(); i++) {
      vector<int> temp = people[i];
      result.insert(result.begin() + temp[1], temp);
    }
    return result;
  }
};
int main() {
  Solution a;
  vector<vector<int>> test = {{6, 0}, {5, 0}, {4, 0}, {3, 2}, {2, 2}, {1, 4}};
  vector<vector<int>> result = a.reconstructQueue(test);
  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result[0].size(); j++) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
