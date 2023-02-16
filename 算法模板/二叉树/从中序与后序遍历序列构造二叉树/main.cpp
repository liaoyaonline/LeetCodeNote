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
  TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
  int post_index;
  map<int, int> index_map;

 public:
  TreeNode* helper(int in_left, int in_right, vector<int>& inorder,
                   vector<int>& postorder) {
    if (in_left > in_right) return nullptr;
    int root_val = postorder[post_index];
    int index = index_map[root_val];
    post_index--;
    TreeNode* root = new TreeNode(root_val);
    root->right = helper(index + 1, in_right, inorder, postorder);
    root->left = helper(in_left, index - 1, inorder, postorder);
    return root;
  }
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    post_index = (int)postorder.size() - 1;
    for (int i = 0; i < inorder.size(); i++) index_map[inorder[i]] = i;
    return helper(0, post_index, inorder, postorder);
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
};
int main() {
  Solution a;
  vector<int> test1{9, 3, 15, 20, 7};
  vector<int> test2{9, 15, 7, 20, 3};
  TreeNode* T = a.buildTree(test1, test2);
  a.preTraversal(T);
  cout << endl;
  a.inorderTraversal(T);
  cout << endl;
  return 0;
}
