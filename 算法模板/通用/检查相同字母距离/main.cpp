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
  bool minWindow(string s, vector<int>& distance) {
    vector<int> hashmap(27, -1);
    for (int i = 0; i < s.size(); i++) {
      int tempnum = s[i] - 'a';
      if (hashmap[tempnum] != -1 &&
          (i - hashmap[tempnum] - 1) != distance[tempnum]) {
        return false;
      }
      hashmap[tempnum] = i;
    }
    return true;
  }
};
int main() {
  Solution a;
  string test = "abaccb";
  vector<int> test2{1, 3, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  cout << a.minWindow(test, test2) << endl;
  return 0;
}
