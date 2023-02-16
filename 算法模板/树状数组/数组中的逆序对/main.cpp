/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin() bool cmp(const word &num1, const word &num2) {
  return num1.value != num2.value ? num1.value > num2.value: num1.name <
 num2.name;} v.insert(v.begin()+3,1);map.containsKey(num) s.substr(i,2)####
queue<pair<TreeNode*,int>> que;que.emplace(root,1);
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
class BIT {
 private:
  vector<int> tree;
  int n;

 public:
  BIT(int _n) : n(_n), tree(_n + 1) {}
  static int lowbit(int x) { return x & (-x); }
  int query(int x) {
    int ret = 0;
    while (x) {
      ret += tree[x];
      x -= lowbit(x);
    }
    return ret;
  }
  void update(int x) {
    while (x <= n) {
      ++tree[x];
      x += lowbit(x);
    }
  }
};
class Solution {
 public:
  int reversePairs(vector<int>& nums) {
    int n = nums.size();
    vector<int> tmp = nums;
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < nums.size(); i++) {
      nums[i] = lower_bound(tmp.begin(), tmp.end(), nums[i]) - tmp.begin() + 1;
    }
    BIT bit(n);
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
      ans += bit.query(nums[i] - 1);
      bit.update(nums[i]);
    }
    return ans;
  }
};
int main() {
  Solution a;
  vector<int> test{5, 4, 4, 4};
  cout << a.reversePairs(test) << endl;
  return 0;
}
