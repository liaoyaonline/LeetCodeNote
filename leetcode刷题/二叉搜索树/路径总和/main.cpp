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
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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
      T = new TreeNode(x);
      CreateTree(T->left);
      CreateTree(T->right);
    }
  }
  void preTraversal(TreeNode* root) {
    if (!root) {
      return;
    }
    cout << root->val << " ";
    preTraversal(root->left);
    preTraversal(root->right);
    return;
  }
  void inorderTraversal(TreeNode* root) {
    if (!root) {
      return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
    return;
  }
  bool dfs(TreeNode* root, int sum) {
    if (root == nullptr) return false;
    if (root->left == nullptr && root->right == nullptr)
      return sum == root->val;
    else
      return dfs(root->left, sum - root->val) ||
             dfs(root->right, sum - root->val);
  }
};
int main() {
  Solution a;
  TreeNode* T;
  vector<int> test{1, 2, 3, 4, 5, 6, 7, 8, 9};
  a.preTraversal(T);
  cout << endl;
  a.inorderTraversal(T);
  cout << endl;
  return 0;
}
