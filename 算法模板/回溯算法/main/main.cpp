/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin() bool cmp(const word &num1, const word &num2) {
  return num1.value != num2.value ? num1.value > num2.value: num1.name <
 num2.name;} v.insert(v.begin()+3,1);map.containsKey(num) s.substr(i,2)####
 cur = gcd(cur,num[j])//返回公约数
 */
#include <bits/stdc++.h>
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
  int minWindow(vector<int>& nums, int k) {
    int n = nums.size();
    int i = 0;
    int j = 0;
    int l = 0;
    int ans = 0;
    for (i = 0; i < n; i++) {
      if (nums[i] % k == 0) {
        for (j = i, l = 0; j < n; j++) {
          l = __gcd(l, nums[j]);
          if (l % k) break;
          if (l == k) ans++;
        }
      }
    }
    return ans;
  }
};
int main() {
  Solution a;
  vector<int> test{9, 3, 6};
  cout << a.minWindow(test, 3) << endl;
  return 0;
}
