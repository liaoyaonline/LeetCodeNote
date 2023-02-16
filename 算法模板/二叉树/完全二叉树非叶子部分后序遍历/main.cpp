/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin() bool cmp(const word &num1, const word &num2) {
  return num1.value != num2.value ? num1.value > num2.value: num1.name <
 num2.name;} v.insert(v.begin()+3,1);map.containsKey(num) s.substr(i,2)####
 */
#include <limits.h>

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
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
 public:
  void backTraversal(vector<int> nums, int index) {
    if (2 * index + 1 >= nums.size() && 2 * index + 2 >= nums.size()) return;
    backTraversal(nums, 2 * index + 1);
    backTraversal(nums, 2 * index + 2);
    cout << nums[index] << " ";
  }
};
int main() {
  Solution a;
  TreeNode* T;
  vector<int> test{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  a.backTraversal(test, 0);
  cout << endl;
  return 0;
}
