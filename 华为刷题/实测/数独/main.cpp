/*pow(16,i),queue.front()####
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
class Solution {
 public:
  vector<vector<int>> result;
  bool checknum(int x, int y, int k, vector<vector<int>> path) {
    for (int i = 0; i < 9; i++) {
      if (path[x][i] == k || path[i][y] == k) return false;
    }
    int tx = x / 3;
    int ty = y / 3;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        int tempx = tx * 3 + i;
        int tempy = ty * 3 + j;
        if (path[tempx][tempy] == k) return false;
      }
    }
    return true;
  }
  void df(int i, int j, vector<vector<int>>& path) {
    if (i == 8 && j == 9) {
      result = path;
      return;
    }
    if (j == 9) {
      i = i + 1;
      j = 0;
    }
    if (path[i][j] == 0) {
      for (int k = 1; k <= 9; k++) {
        if (checknum(i, j, k, path)) {
          path[i][j] = k;
          df(i, j + 1, path);
          path[i][j] = 0;
        }
      }
    } else
      df(i, j + 1, path);
  }
  void printnum(vector<vector<int>>& path) {
    df(0, 0, path);
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) cout << result[i][j] << " ";
      cout << endl;
    }
  }
};
int main() {
  Solution a;
  vector<vector<int>> path(9, vector<int>(9, 0));
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      int temp = 0;
      cin >> temp;
      path[i][j] = temp;
    }
  }
  a.printnum(path);
  return 0;
}
