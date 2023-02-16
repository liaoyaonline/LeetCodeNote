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
  int minWindow(string croakOfFrogs) {
    if (croakOfFrogs.size() % 5 != 0) return -1;
    vector<int> nums(5, 0);
    int num = 0;
    int ret = 0;
    for (int i = 0; i < croakOfFrogs.size(); i++) {
      switch (croakOfFrogs[i]) {
        case 'c':
          num++;
          ret = max(ret, num);
          nums[0]++;
          break;
        case 'r':
          nums[1]++;
          if (nums[1] > nums[0]) return -1;
          break;
        case 'o':
          nums[2]++;
          if (nums[2] > nums[1]) return -1;
          break;
        case 'a':
          nums[3]++;
          if (nums[3] > nums[2]) return -1;
          break;
        case 'k':
          nums[4]++;
          num--;
          if (nums[4] > nums[3]) return -1;
          break;
        default:
          return -1;
      }
    }
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != nums[0]) return -1;
    }
    return ret;
  }
};
int main() {
  Solution a;
  string test;
  getline(cin, test);
  cout << a.minWindow(test) << endl;
  return 0;
}
