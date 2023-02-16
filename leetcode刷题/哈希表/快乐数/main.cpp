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
  bool minWindow(int n) {
    map<int, int> hashmap;
    int sum = n;
    while (1) {
      int a = sum;
      int b = 0;
      int tempsum = 0;
      while (1) {
        b = a % 10;
        a = a / 10;
        tempsum += b * b;
        if (a == 0) {
          sum = tempsum;
          break;
        }
      }
      if (sum == 1) return true;
      if (sum != 1 && hashmap[sum] == 1) return false;
      hashmap[sum] = 1;
    }
    return true;
  }
};
int main() {
  Solution a;
  cout << a.minWindow(1) << endl;
  return 0;
}
