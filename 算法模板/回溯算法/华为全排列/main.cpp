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
  int result;
  map<string, int> hashmap;
  void backtrack(string& S, int start, int end) {
    if (start == end) {
      if (hashmap[S] == 1) {
        return;
      } else {
        result++;
        hashmap[S] = 1;
      }
    }
    for (int i = start; i < end; i++) {
      swap(S[i], S[start]);
      backtrack(S, start + 1, end);
      swap(S[i], S[start]);
    }
  }
  int minWindow(string& S) {
    if (S.size() == 0) return 0;
    result = 0;
    backtrack(S, 0, S.size());
    return result;
  }
};
int main() {
  Solution a;
  string test = "ABCDEFGHHA";
  cout << a.minWindow(test) << endl;
  return 0;
}
