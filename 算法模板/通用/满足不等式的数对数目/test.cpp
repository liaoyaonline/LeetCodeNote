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
  long long minWindow(vector<int> nums1, vector<int> nums2, int diff) {
    int n = nums1.size();
    vector<int> dp(n, 0);
    long long res = 0;
    for (int i = 0; i < n; i++) {
      dp[i] = nums1[i] - nums2[i];
    }
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (dp[i] <= dp[j] + diff) res++;
      }
    }
    return res;
  }
};
int main() {
  Solution a;
  vector<int> test1{3, 2, 5};
  vector<int> test2{2, 2, 1};
  int diff = 1;
  cout << a.minWindow(test1, test2, diff) << endl;
  return 0;
}
