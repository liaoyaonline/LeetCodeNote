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
  char val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
  int post_idx;
  map<char, int> idx_map;

 public:
  TreeNode* helper(int in_left, int in_right, string& inorder,
                   string& postorder) {
    if (in_left > in_right) return nullptr;
    char root_val = postorder[post_idx];
    TreeNode* root = new TreeNode(root_val);
    int index = idx_map[root_val];
    post_idx--;
    root->right = helper(index + 1, in_right, inorder, postorder);
    root->left = helper(in_left, index - 1, inorder, postorder);
    return root;
  }
  TreeNode* buildTree(string& inorder, string& postorder) {
    post_idx = (int)postorder.size() - 1;
    for (int i = 0; i < inorder.size(); i++) {
      idx_map[inorder[i]] = i;
    }
    return helper(0, (int)inorder.size() - 1, inorder, postorder);
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
  TreeNode* dfs(vector<int>& nums, int left, int right) {
    if (left > right) return nullptr;
    int mid = (left + right) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = dfs(nums, left, mid - 1);
    root->right = dfs(nums, mid + 1, right);
    return root;
  }
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return dfs(nums, 0, nums.size() - 1);
  }
  int minDepth(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
      return 1;
    }
    int min_depth = INT_MAX;
    if (root->left != nullptr) {
      min_depth = min(minDepth(root->left), min_depth);
    }
    if (root->right != nullptr) {
      min_depth = min(minDepth(root->right), min_depth);
    }

    return min_depth + 1;
  }
  int minDepth2(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }

    queue<pair<TreeNode*, int>> que;
    que.emplace(root, 1);
    while (!que.empty()) {
      TreeNode* node = que.front().first;
      int depth = que.front().second;
      que.pop();
      if (node->left == nullptr && node->right == nullptr) {
        return depth;
      }
      if (node->left != nullptr) {
        que.emplace(node->left, depth + 1);
      }
      if (node->right != nullptr) {
        que.emplace(node->right, depth + 1);
      }
    }
    return 0;
  }
};
int main() {
  Solution a;
  string test1 = "CBAEDF";
  string test2 = "CBEFDA";
  TreeNode* T = a.buildTree(test1, test2);
  a.preTraversal(T);
  cout << endl;
  a.inorderTraversal(T);
  cout << endl;
  cout << a.minDepth(T) << endl;
  cout << a.minDepth2(T) << endl;
  return 0;
}
