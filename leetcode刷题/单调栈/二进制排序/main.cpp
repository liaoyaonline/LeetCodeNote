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
  int secondsToRemoveOccurrences(string s) {
    int zeroindex = 0;
    int oneindex = s.size() - 1;
    int onenums = 0;
    int minpath = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '0') {
        zeroindex = i;
        break;
      }
    }
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] == '1') {
        oneindex = i;
        break;
      }
    }
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '1') onenums++;
    }
    minpath = max(abs(zeroindex - onenums), abs(oneindex + 1 - onenums));
    return minpath;
  }
};
int main() {
  Solution a;
  string test = "11100";
  cout << a.secondsToRemoveOccurrences(test) << endl;
  return 0;
}
