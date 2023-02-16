/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..)####
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
  bool isValidSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.')
          continue;
        else {
          for (int p = 0; p < 9; p++) {
            if (p != j && board[i][p] == board[i][j]) return false;
          }
          for (int q = 0; q < 9; q++) {
            if (q != i && board[q][j] == board[i][j]) return false;
          }
          int tempx = i / 3;
          int tempy = j / 3;
          for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
              int tempfirst = (tempx * 3) + x;
              int tempsecond = (tempy * 3) + y;
              if (i != tempfirst && j != tempsecond &&
                  board[tempfirst][tempsecond] == board[i][j])
                return false;
            }
          }
        }
      }
    }
    return true;
  }
};
int main() {
  Solution a;
  vector<vector<char>> board;
  cout << a.isValidSudoku(board) << endl;
  return 0;
}
