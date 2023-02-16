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
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
struct TreeNode {
  char val;
  TreeNode* left;
  TreeNode* right;
};
class Solution {
 public:
  void CreateTree(TreeNode*& T) {
    char x;
    cin >> x;
    if (x == '#') {
      T = NULL;
      return;
    } else {
      T = new TreeNode;
      T->val = x;
      CreateTree(T->left);
      CreateTree(T->right);
    }
  }
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr)
      return true;
    else if (p == nullptr || q == nullptr)
      return false;
    else if (p->val != q->val)
      return false;
    else {
      return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
  }
};
int main() {
  Solution a;
  TreeNode* T;
  a.CreateTree(T);
  TreeNode* T2;
  a.CreateTree(T2);
  cout << a.isSameTree(T, T2) << endl;
  return 0;
}
