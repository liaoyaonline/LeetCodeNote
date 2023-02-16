/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin() bool cmp(const word &num1, const word &num2) {
  return num1.value != num2.value ? num1.value > num2.value: num1.name <
 num2.name;} v.insert(v.begin()+3,1);####
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
  bool firstUniqChar(string s) {
    int nums[26] = {0};
    for (int i = 0; i < s.size(); i++) {
      int tempnum = s[i] - 'a';
      nums[tempnum]++;
    }
    for (int i = 0; i < s.size(); i++) {
      int tempnum = s[i] - 'a';
      if (nums[tempnum] == 1) return i;
    }
    return -1;
  }
};
int main() {
  Solution a;
  string test = "loveleetcode";
  cout << a.firstUniqChar(test) << endl;
  return 0;
}
