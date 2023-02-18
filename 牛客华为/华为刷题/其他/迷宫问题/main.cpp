#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<pair<int, int>> res;
  void dfs(vector<vector<int>>& maze, int n, int m, int i, int j,
           vector<pair<int, int>>& path) {
    path.push_back(make_pair(i, j));
    maze[i][j] = 1;
    if (i == n - 1 && j == m - 1) {
      res = path;
      return;
    }
    if (i + 1 < n && maze[i + 1][j] == 0) dfs(maze, n, m, i + 1, j, path);
    if (i - 1 >= 0 && maze[i - 1][j] == 0) dfs(maze, n, m, i - 1, j, path);
    if (j + 1 < m && maze[i][j + 1] == 0) dfs(maze, n, m, i, j + 1, path);
    if (j - 1 >= 0 && maze[i][j - 1] == 0) dfs(maze, n, m, i, j - 1, path);
    path.pop_back();
    maze[i][j] = 0;
  }
  vector<pair<int, int>> Maze(vector<vector<int>> maze) {
    int n = maze.size();
    int m = maze[0].size();
    vector<pair<int, int>> path;
    dfs(maze, n, m, 0, 0, path);
    return res;
  }
};
int main() {
  Solution a;
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> Result;
  vector<vector<int>> maze(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> maze[i][j];
  Result = a.Maze(maze);
  for (int i = 0; i < Result.size(); i++)  //输出路径
    cout << "(" << Result[i].first << "," << Result[i].second << ")" << endl;
  return 0;
}
