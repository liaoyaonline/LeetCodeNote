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
  TreeNode *left, *right;
};
class Solution {
 public:
  vector<vector<int>> PrintFromTopToBottom(TreeNode *root) {
    vector<vector<int>> result;
    int level = 0;
    if (root == NULL) return result;
    queue<TreeNode *> treequeue;
    treequeue.push(root);
    while (!treequeue.empty()) {
      vector<int> tempnum;
      int size = treequeue.size();
      for (int i = 0; i < size; i++) {
        TreeNode *temptree = treequeue.front();
        treequeue.pop();
        if (temptree->left) treequeue.push(temptree->left);
        if (temptree->right) treequeue.push(temptree->right);
        if (level % 2 == 0)
          tempnum.push_back(temptree->val);
        else
          tempnum.insert(tempnum.begin(), temptree->val);
      }
      level++;
      result.push_back(tempnum);
    }
    return result;
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
  vector<vector<int>> result;
  int nums[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  for (int i = 0; i < 12; i++) {
    a.CreateTreeNode(&root, nums[i]);
  }
  a.PreOrderTraversal(root);
  cout << endl;
  a.InOrderTraversal(root);
  cout << endl;
  result = a.PrintFromTopToBottom(root);
  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result[i].size(); j++) {
      cout << result[i][j] << " ";
    }
  }
  cout << endl;
  return 0;
}
