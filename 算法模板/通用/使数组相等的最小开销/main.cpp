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
  long long minWindow(vector<int>& nums, vector<int>& cost) {
    long long sum = LLONG_MAX;
    for (int i = 0; i < nums.size(); i++) {
      int flagnum = nums[i];
      long long tempsum = 0;
      for (int j = 0; j < nums.size(); j++) {
        if (nums[j] == flagnum) {
          continue;
        }
        int tempabs = abs(flagnum - nums[j]);
        tempsum += ((long long)tempabs * (long long)cost[j]);
      }
      sum = min(sum, tempsum);
    }
    return sum;
  }
};
int main() {
  Solution a;
  vector<int> test{1, 3, 5, 2};
  vector<int> test2{2, 3, 1, 14};
  cout << a.minWindow(test, test2) << endl;
  return 0;
}
