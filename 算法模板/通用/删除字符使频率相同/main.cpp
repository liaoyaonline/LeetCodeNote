/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin() bool cmp(const word &num1, const word &num2) {
  return num1.value != num2.value ? num1.value > num2.value: num1.name <
 num2.name;} v.insert(v.begin()+3,1);map.containsKey(num) s.substr(i,2)####
string b= to_string(int a); int a =
atoi(b.c_str());d.emplace(d.begin()+1,4)在0后，1前面插入4
d.erase(d.begin()+1);删除1坐标上的数据*/
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
  bool minWindow(string word) {
    vector<int> hashmap(26, 0);
    for (int i = 0; i < word.size(); i++) {
      int tempindex = word[i] - 'a';
      hashmap[tempindex]++;
    }
    for (int i = 0; i < 26; i++) {
      if (hashmap[i] != 0) {
        hashmap[i]--;
        int flag = 0;
        for (int j = 0; j < 26; j++) {
          if (hashmap[j] != 0) {
            flag = hashmap[j];
            break;
          }
        }
        int res = 0;
        for (int j = 0; j < 26; j++) {
          if (hashmap[j] != 0 && hashmap[j] != flag) {
            res = 1;
            break;
          }
        }
        hashmap[i]++;
        if (res == 0) {
          return true;
        }
      }
    }
    return false;
  }
};
int main() {
  Solution a;
  string test = "babbdd";
  cout << a.minWindow(test) << endl;
  return 0;
}
