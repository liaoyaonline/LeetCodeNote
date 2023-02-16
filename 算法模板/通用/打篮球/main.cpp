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
  int minsum;
  int curr;
  void dfs(vector<int>& nums, int index, int pathlen, int len, int cursum,
           int sum) {
    if (pathlen == 5) {
      int tempmin = abs(sum - cursum - cursum);
      minsum = min(tempmin, minsum);
      curr++;
      return;
    }
    if (index == len) {
      return;
    }
    for (int i = index; i < len; i++) {
      dfs(nums, i + 1, pathlen + 1, len, cursum + nums[i], sum);
    }
  }
  int minWindow(vector<int>& nums) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
    }
    minsum = sum;
    curr = 0;
    dfs(nums, 0, 0, nums.size(), 0, sum);
    cout << curr << endl;
    return minsum;
  }
};
int main() {
  Solution a;
  vector<int> test{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  cout << a.minWindow(test) << endl;
  return 0;
}
