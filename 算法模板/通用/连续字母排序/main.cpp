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
  int minWindow(string S, int k) {
    vector<int> hashmap(27, 0);
    int tempmax = 1;
    char flag = S[0];
    for (int i = 1; i < S.size(); i++) {
      if (S[i] != flag) {
        int tempnum = flag - 'A';
        hashmap[tempnum] = max(tempmax, hashmap[tempnum]);
        tempmax = 1;
        flag = S[i];
        continue;
      }
      tempmax++;
    }
    hashmap[flag - 'A'] = max(tempmax, hashmap[flag - 'A']);
    sort(hashmap.begin(), hashmap.end(), [](int u, int v) { return u > v; });
    return hashmap[k - 1];
  }
};
int main() {
  Solution a;
  string test;
  int K;
  getline(cin, test);
  cin >> K;
  cout << a.minWindow(test, K) << endl;
  return 0;
}
