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
//并查集类
class UnionFind {
 public:
  UnionFind(vector<vector<char>>& grid) {
    count = 0;
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '1') {
          parent.push_back(i * n + j);
          ++count;
        } else {
          parent.push_back(-1);
        }
        rank.push_back(0);
      }
    }
  }
  int find(int i) {
    if (parent[i] != i) {
      parent[i] = find(parent[i]);
    }
    return parent[i];
  }
  void unite(int x, int y) {
    int rootx = find(x);
    int rooty = find(y);
    if (rootx != rooty) {
      if (rank[rootx] < rank[rooty]) {
        swap(rootx, rooty);
      }
      parent[rooty] = rootx;
      if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
      --count;
    }
  }
  int getCount() const { return count; }

 private:
  vector<int> parent;
  vector<int> rank;
  int count;
};
class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int nr = grid.size();
    if (!nr) return 0;
    int nc = grid[0].size();

    UnionFind uf(grid);
    int num_islands = 0;
    for (int r = 0; r < nr; ++r) {
      for (int c = 0; c < nc; ++c) {
        if (grid[r][c] == '1') {
          grid[r][c] = '0';
          if (r - 1 >= 0 && grid[r - 1][c] == '1')
            uf.unite(r * nc + c, (r - 1) * nc + c);
          if (r + 1 < nr && grid[r + 1][c] == '1')
            uf.unite(r * nc + c, (r + 1) * nc + c);
          if (c - 1 >= 0 && grid[r][c - 1] == '1')
            uf.unite(r * nc + c, r * nc + c - 1);
          if (c + 1 < nc && grid[r][c + 1] == '1')
            uf.unite(r * nc + c, r * nc + c + 1);
        }
      }
    }
    return uf.getCount();
  }
};
int main() {
  vector<vector<char>> test{{'1', '1', '0', '0', '0'},
                            {'1', '1', '0', '0', '0'},
                            {'0', '0', '1', '0', '0'},
                            {'0', '0', '0', '1', '1'}};
  Solution a;
  cout << a.numIslands(test) << endl;
  return 0;
}
