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
class DisJointSetUnion {
 private:
  vector<int> parent;

 public:
  DisJointSetUnion(int n) {
    for (int i = 0; i < n + 1; i++) {
      parent.push_back(0);
    }
  }

  int find(int x) {
    if (x == parent[x])
      return x;
    else {
      return parent[x];
    }
  }
  void del(int x) {
    if (parent[x] == 0) return;
    queue<int> que;
    que.push(x);
    while (!que.empty()) {
      int index = que.front();
      que.pop();
      parent[index] = 0;
      for (int i = 0; i < parent.size(); i++) {
        if (parent[i] == x) {
          que.push(i);
        }
      }
    }
  }

  void merge(int x, int y) { parent[x] = y; }
  vector<int> remain() {
    vector<int> res;
    for (int i = 0; i < parent.size(); i++) {
      if (parent[i] != 0) {
        res.push_back(i);
      }
    }
    return res;
  }
};
class Solution {
 public:
  vector<int> findCircleNum(vector<vector<int>>& edges, int MaxNum,
                            vector<int> del) {
    int n = edges.size();
    DisJointSetUnion uf(MaxNum);
    for (int i = 0; i < n; i++) {
      uf.merge(edges[i][0], edges[i][1]);
    }
    for (int i = 0; i < del.size(); i++) {
      uf.del(del[i]);
    }
    return uf.remain();
  }
};
int main() {
  Solution a;
  vector<vector<int>> test{{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
  vector<int> del{5, 1};
  vector<int> res = a.findCircleNum(test, 7, del);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}
