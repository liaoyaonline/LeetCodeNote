/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin() bool cmp(const word &num1, const word &num2) {
  return num1.value != num2.value ? num1.value > num2.value: num1.name <
 num2.name;} v.insert(v.begin()+3,1);map.containsKey(num) s.substr(i,2)####
string b= to_string(int a); int a =
atoi(b.c_str());d.emplace(d.begin()+1,4)在0后，1前面插入4
d.erase(d.begin()+1);删除1坐标上的数据*/
#include <limits.h>

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
  int gcd(int a, int b) {
    if (a % b == 0) {
      return b;
    } else {
      return (gcd(b, a % b));
    }
  }
  int minnum(int a, int b) {
    int c = gcd(a, b);
    return (a / c) * (b / c) * c;
  }
  int minWindow(vector<int>& nums, int k) {
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (k % nums[i] == 0) {
        int lcm = nums[i];
        for (int j = i; j < nums.size(); j++) {
          lcm = minnum(lcm, nums[j]);
          if (lcm == k) {
            res++;
          }
          if (lcm > k) break;
        }
      }
    }
    return res;
  }
};
int main() {
  Solution a;
  vector<int> test{3, 6, 2, 7, 1};
  cout << a.minWindow(test, 6) << endl;
  return 0;
}
