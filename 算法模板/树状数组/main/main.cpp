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
  vector<int> tree;  //存储各个父节点的值
  int n;

 public:
  BIT(int _n) : n(_n), tree(_n + 1) {}           //初始化，全部为0
  static int lowbit(int x) { return x & (-x); }  //计算最低位的1
  int query(int x) {  //查询，加上最低位1的位置减去1
    int ret = 0;
    while (x) {
      ret += tree[x];
      x -= lowbit(x);
    }
    return ret;
  }
  void update(int x) {  //加入数时，在最低位1的位置加1
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
    sort(tmp.begin(), tmp.end());  //排序
    for (int i = 0; i < nums.size(); i++) {
      nums[i] = lower_bound(tmp.begin(), tmp.end(), nums[i]) - tmp.begin() +
                1;  //计算每个数的相对位置，比如7排在4,5,6,7的第4个
    }
    BIT bit(n);
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
      ans += bit.query(nums[i] - 1);  //先查询
      bit.update(nums[i]);            //再更新
    }
    return ans;
  }
};
int main() {
  Solution a;
  vector<int> test{7, 5, 6, 4};
  cout << a.reversePairs(test) << endl;
  return 0;
}
