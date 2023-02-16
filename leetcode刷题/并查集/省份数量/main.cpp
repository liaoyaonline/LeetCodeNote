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
  vector<int> rank;

 public:
  DisJointSetUnion(int n) {
    for (int i = 0; i < n; i++) {
      parent.push_back(i);
      rank.push_back(1);
    }
  }

  int find(int x) {
    if (x == parent[x])
      return x;
    else {
      parent[x] = find(parent[x]);
      return parent[x];
    }
  }

  void merge(int x, int y) {
    int rx = find(x);
    int ry = find(y);

    if (rx != ry) {
      if (rank[rx] < rank[ry]) {
        swap(rx, ry);
      }

      parent[ry] = rx;

      if (rank[rx] == rank[ry]) rank[rx] += 1;
    }
  }
};
class Solution {
 public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    DisJointSetUnion uf(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (isConnected[i][j] == 1) {
          uf.merge(i, j);
        }
      }
    }
    int nums = 0;
    for (int i = 0; i < n; i++) {
      if (uf.find(i) == i) {
        nums++;
      }
    }
    return nums;
  }
};
int main() {
  Solution a;
  vector<vector<int>> test{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  cout << a.findCircleNum(test) << endl;
  return 0;
}
