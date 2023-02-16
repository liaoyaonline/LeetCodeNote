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
  string getstrnum(int n) {
    string result = to_string(n);
    while (result.size() < 4) result.push_back('*');
    return result;
  }
  int minWindow(int n) {
    int k = 1;
    int flag = 0;
    for (int i = 1; i <= n; i++) {
      if (flag % 2 == 0) {
        string temp = getstrnum(k);
        cout << temp;
        for (int j = k + 1; j < k + i; j++) {
          string tempstr = getstrnum(j);
          cout << "    " << tempstr;
        }
        cout << endl;
      }
      if (flag % 2 == 1) {
        string temp = getstrnum(k + i - 1);
        cout << temp;
        for (int j = k + i - 2; j >= k; j--) {
          string tempstr = getstrnum(j);
          cout << "    " << tempstr;
        }
        cout << endl;
      }
      flag++;
      k = k + i;
    }
    return true;
  }
};
int main() {
  Solution a;
  a.minWindow(3);
  return 0;
}
