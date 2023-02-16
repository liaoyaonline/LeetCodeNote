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
//并查集类
class DisJointSetUnion {
 private:
  // 所有根结点相同的结点位于同一个集合中
  vector<int>
      parent;  // 双亲结点数组，记录该结点的双亲结点，用于查找该结点的根结点
  vector<int>
      rank;  // 秩数组，记录以该结点为根结点的树的深度，主要用于优化，在合并两个集合的时候，rank大的集合合并rank小的集合

 public:
  void dfs(vector<vector<char>>& board, int i, int j) {
    if (i >= board.size() || j >= board[0].size() || board[i][j] != 'O') return;
    board[i][j] = 'A';
    dfs(board, i + 1, j);
    dfs(board, i - 1, j);
    dfs(board, i, j + 1);
    dfs(board, i, j - 1);
  }
  void solve(vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();
    for (int i = 0; i < n; i++) {
      if (board[i][0] == 'O') dfs(board, i, 0);
      if (board[i][m - 1] == 'O') dfs(board, i, m - 1);
    }
    for (int i = 1; i < m - 1; i++) {
      if (board[0][i] == 'O') dfs(board, 0, i);
      if (board[n - 1][i] == 'O') dfs(board, n - 1, i);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == 'O') board[i][j] = 'X';
        if (board[i][j] == 'A') board[i][j] = 'O';
      }
    }
  }
};
int main() {
  TreeNode* T;
  vector<vector<char>> test{{'X', 'X', 'X', 'X'},
                            {'X', 'O', 'O', 'X'},
                            {'X', 'X', 'O', 'X'},
                            {'X', 'O', 'X', 'X'}};
  DisJointSetUnion a;
  a.solve(test);
  for (int i = 0; i < test.size(); i++) {
    for (int j = 0; j < test[0].size(); j++) cout << test[i][j] << " ";
    cout << endl;
  }
  return 0;
}
