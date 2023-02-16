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
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  int minWindow(string s) {
    map<char, int> hashmap;
    hashmap['q'] = 1;
    hashmap['u'] = 1;
    hashmap['a'] = 1;
    hashmap['c'] = 1;
    hashmap['k'] = 1;
    queue<int> st;
    int maxlen = 0;
    for (int i = 0; i < s.size(); i++) {
      if (hashmap.find(s[i]) == hashmap.end()) return -1;
      hashmap[s[i]]++;
      if (s[i] == 'q') {
        st.push(i);
        int templen = st.size();
        maxlen = max(maxlen, templen);
        continue;
      }
      if (!st.empty() && s[i] == 'k') {
        st.pop();
        continue;
      }
    }
    int N = hashmap['q'];
    for (auto it = hashmap.begin(); it != hashmap.end(); it++) {
      if (it->second != N || it->second <= 1) return -1;
    }
    return maxlen;
  }
};
int main() {
  Solution a;
  string test;
  getline(cin, test);
  cout << a.minWindow(test) << endl;
  return 0;
}
