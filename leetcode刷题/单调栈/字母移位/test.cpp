/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin() bool cmp(const word &num1, const word &num2) {
  return num1.value != num2.value ? num1.value > num2.value: num1.name <
 num2.name;} v.insert(v.begin()+3,1);map.containsKey(num)####
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
  string minWindow(string s, vector<vector<int>>& shifts) {
    string result = s;
    int nums[s.size()] = {0};
    for (int i = 0; i < shifts.size(); i++) {
      if (shifts[i][2] == 0) {
        for (int j = shifts[i][0]; j <= shifts[i][1]; j++) nums[j]--;
      } else if (shifts[i][2] == 1) {
        for (int j = shifts[i][0]; j <= shifts[i][1]; j++) nums[j]++;
      }
    }
    for (int i = 0; i < result.size(); i++) {
      int tempnum = (result[i] - 'a' + 2600 + nums[i]) % 26;
      result[i] = 'a' + tempnum;
    }
    return result;
  }
};
int main() {
  Solution a;
  string str1 = "abc";
  vector<vector<int>> test{{0, 1, 0}, {1, 2, 1}, {0, 2, 1}};
  cout << a.minWindow(str1, test) << endl;
  return 0;
}
