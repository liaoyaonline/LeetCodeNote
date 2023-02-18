#include <iostream>
#include <queue>
#include <map>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left, *right;
};
class Solution {
 public:
  map<TreeNode *, int> hs;
  int depth(TreeNode *root) {
    if (!root) return 0;
    if (hs.find(root) != hs.end()) {
        cout << "ceshi" << endl;
        return hs[root];
    }
    int ldep = depth(root->left);
    int rdep = depth(root->right);
    return hs[root] = max(ldep, rdep) + 1;
  }
  bool judge(TreeNode *root) {
    if (!root) return true;
    return abs(hs[root->left] - hs[root->right]) <= 1 && judge(root->left) &&
           judge(root->right);
  }
  bool IsBalanced_Solution(TreeNode *pRoot) {
    depth(pRoot);
    return judge(pRoot);
  }
  void CreateTreeNode(TreeNode **T, int value) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    queue<TreeNode *> NodeQueue;
    if (*T == NULL) {
      *T = node;
      return;
    } else {
      NodeQueue.push(*T);
      TreeNode *temp = NULL;
      while (!NodeQueue.empty()) {
        temp = NodeQueue.front();
        cout << temp->val << endl;
        if (temp->left == NULL) {
          temp->left = node;
          break;
        }
        if (temp->right == NULL) {
          temp->right = node;
          break;
        }
        if (temp->left != NULL) {
          NodeQueue.push(temp->left);
        }
        if (temp->right != NULL) {
          NodeQueue.push(temp->right);
        }
        NodeQueue.pop();
      }
    }
  }
  void PreOrderTraversal(TreeNode *pRoot) {
    if (pRoot) {
      cout << pRoot->val << " ";
      PreOrderTraversal(pRoot->left);
      PreOrderTraversal(pRoot->right);
    }
  }
  void InOrderTraversal(TreeNode *pRoot) {
    if (pRoot) {
      InOrderTraversal(pRoot->left);
      cout << pRoot->val << " ";
      InOrderTraversal(pRoot->right);
    }
  }
};
int main() {
  Solution a;
  TreeNode *root = NULL;
  int nums[12] = {1,2,3,4,5,6,7,8,9,10,11};
  for (int i = 0; i < 12; i++) {
    a.CreateTreeNode(&root, nums[i]);
  }
  a.PreOrderTraversal(root);
  cout << endl;
  a.InOrderTraversal(root);
  cout << a.IsBalanced_Solution(root) << endl;
  return 0;
}
