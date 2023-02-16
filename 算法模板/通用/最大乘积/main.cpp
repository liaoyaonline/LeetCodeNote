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
  int minWindow(vector<string> s) {
    int maxnum = 0;
    for (int i = 0; i < s.size(); i++) {
      vector<int> hashmap(27, 0);
      for (int k = 0; k < s[i].size(); k++) {
        int tempindex = s[i][k] - 'a';
        hashmap[tempindex] = 1;
      }
      for (int j = i + 1; j < s.size(); j++) {
        int flag = 0;
        for (int l = 0; l < s[j].size(); l++) {
          int lnum = s[j][l] - 'a';
          if (hashmap[lnum] == 1) {
            flag = 1;
            break;
          }
        }
        if (flag == 0) {
          int tempsum = s[i].size() * s[j].size();
          maxnum = max(maxnum, tempsum);
        }
      }
    }
    return maxnum;
  }
};
int main() {
  Solution a;
  vector<string> test{"iwdvpbn", "hk", "iuop", "iikd", "kadgpf"};
  cout << a.minWindow(test) << endl;
  return 0;
}
