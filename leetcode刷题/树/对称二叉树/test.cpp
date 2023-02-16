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
  void Pre_Traversal(TreeNode* root, vector<int>& result) {
    if (root) {
      result.push_back(root->val);
      Pre_Traversal(root->left, result);
      Pre_Traversal(root->right, result);
    }
  }
  void In_Traversal(TreeNode* root, vector<int>& result) {
    if (root) {
      In_Traversal(root->left, result);
      result.push_back(root->val);
      In_Traversal(root->right, result);
    }
  }
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    In_Traversal(root, res);
    return res;
  }
  vector<int> preTraversal(TreeNode* root) {
    vector<int> res;
    Pre_Traversal(root, res);
    return res;
  }
  bool isSameTree(TreeNode* p, TreeNode* q) {
    vector<int> prep = preTraversal(p);
    vector<int> inp = inorderTraversal(p);
    vector<int> preq = preTraversal(q);
    vector<int> inq = inorderTraversal(q);
    return prep == preq && inp == inq;
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
