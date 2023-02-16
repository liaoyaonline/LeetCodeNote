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
  vector<int> split(string s, char ch) {
    vector<int> res;
    if (s.empty()) return res;
    string tempstr = "";
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ch) {
        int tempnum = atoi(tempstr.c_str());
        res.push_back(tempnum);
        tempstr = "";
        continue;
      }
      tempstr.push_back(s[i]);
    }
    int tempnum2 = atoi(tempstr.c_str());
    res.push_back(tempnum2);
    return res;
  }
  string minWindow(string& s) {
    char maxh1 = '2';
    char maxh2 = '9';
    char maxm1 = '5';
    char maxm2 = '9';
    if (s[0] == '2') maxh2 = '3';
    vector<char> hashmap(4, 0);
    hashmap[0] = s[0];
    hashmap[1] = s[1];
    hashmap[2] = s[3];
    hashmap[3] = s[4];
    sort(hashmap.begin(), hashmap.end());
    for (int i = 0; i < hashmap.size(); i++) {
      if (hashmap[i] > s[4] && hashmap[i] <= maxm2) {
        s[4] = hashmap[i];
        return s;
      }
    }
    s[4] = hashmap[0];
    for (int i = 0; i < hashmap.size(); i++) {
      if (hashmap[i] > s[3] && hashmap[i] <= maxm1) {
        s[3] = hashmap[i];
        return s;
      }
    }
    s[3] = hashmap[0];
    for (int i = 0; i < hashmap.size(); i++) {
      if (hashmap[i] > s[1] && hashmap[i] <= maxh2) {
        s[1] = hashmap[i];
        return s;
      }
    }
    s[1] = hashmap[0];
    for (int i = 0; i < hashmap.size(); i++) {
      if (hashmap[i] > s[0] && hashmap[i] <= maxh1) {
        s[0] = hashmap[i];
        return s;
      }
    }
    s[0] = hashmap[0];
    return s;
  }
};
int main() {
  Solution a;
  string test;
  cin >> test;
  cout << a.minWindow(test) << endl;
  return 0;
}
