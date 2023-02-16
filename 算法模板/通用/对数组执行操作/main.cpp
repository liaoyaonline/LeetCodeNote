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
  vector<int> minWindow(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, 0);
    for (int i = 0; i < n - 1; i++) {
      if (nums[i] == nums[i + 1] && nums[i] != 0) {
        nums[i] = 2 * nums[i];
        nums[i + 1] = 0;
      }
    }
    for (int i = 0, j = 0; i < n; i++) {
      if (nums[i] != 0) {
        res[j] = nums[i];
        j++;
      }
    }
    return res;
  }
};
int main() {
  Solution a;
  vector<int> test{0, 1};
  vector<int> res = a.minWindow(test);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}
