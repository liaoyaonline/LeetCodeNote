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
class Solution {
 public:
  bool minWindow(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.') continue;
        for (int h = 0; h < 9; h++)
          if (h != i && board[h][j] == board[i][j]) return false;
        for (int s = 0; s < 9; s++)
          if (s != j && board[i][s] == board[i][j]) return false;
        int xnum = i / 3;
        int ynum = j / 3;
        for (int x = 0; x < 3; x++) {
          for (int y = 0; y < 3; y++) {
            int tempx = (xnum * 3) + x;
            int tempy = (ynum * 3) + y;
            if (tempx != i && tempy != j && board[tempx][tempy] == board[i][j])
              return false;
          }
        }
      }
    }
    return true;
  }
};
int main() {
  Solution a;
  vector<vector<char>> test{{"5", "3", ".", ".", "7", ".", ".", ".", "."},
                            {"6", ".", ".", "1", "9", "5", ".", ".", "."},
                            {".", "9", "8", ".", ".", ".", ".", "6", "."},
                            {"8", ".", ".", ".", "6", ".", ".", ".", "3"},
                            {"4", ".", ".", "8", ".", "3", ".", ".", "1"},
                            {"7", ".", ".", ".", "2", ".", ".", ".", "6"},
                            {".", "6", ".", ".", ".", ".", "2", "8", "."},
                            {".", ".", ".", "4", "1", "9", ".", ".", "5"},
                            {".", ".", ".", ".", "8", ".", ".", "7", "9"}};
  cout << a.minWindow(test) << endl;
  return 0;
}
