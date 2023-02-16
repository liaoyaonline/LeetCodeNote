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
  TreeNode* reverseOddLevels(TreeNode* root) {
    queue<TreeNode*> qe;
    vector<TreeNode*> st;
    queue<int> depth;
    qe.push(root);
    depth.push(0);
    while (!qe.empty()) {
      TreeNode* temptree = qe.front();
      int tempdepth = depth.front();
      if (tempdepth % 2 != 0) {
        int n = pow(2, tempdepth);
        st.push_back(temptree);
        if (st.size() == n) {
          for (int i = 0; i < n / 2; i++) {
            swap(st[i]->val, st[n - i - 1]->val);
          }
          vector<TreeNode*> test;
          st = test;
        }
      }
      if (temptree->left != nullptr) {
        qe.push(temptree->left);
        depth.push(tempdepth + 1);
        qe.push(temptree->right);
        depth.push(tempdepth + 1);
      }
      qe.pop();
      depth.pop();
    }
    return root;
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
  TreeNode* T;
  vector<int> test{1, 2, 3, 4, 5, 6, 7};
  T = a.sortedArrayToBST(test);
  T = a.reverseOddLevels(T);
  a.preTraversal(T);
  cout << endl;
  a.inorderTraversal(T);
  cout << endl;
  cout << a.minDepth(T) << endl;
  cout << a.minDepth2(T) << endl;
  return 0;
}
