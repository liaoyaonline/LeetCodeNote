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
  char val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
 public:
  void dfs(string frontstr, string orderstr, int fstart, int fend, int ostart,
           int oend) {
    queue<vector<int>> qu;
    vector<int> curr(4, 0);
    curr[0] = fstart;
    curr[1] = fend;
    curr[2] = ostart;
    curr[3] = oend;
    qu.push(curr);
    while (!qu.empty()) {
      vector<int> tempcurr = qu.front();
      qu.pop();
      int tempfstart = tempcurr[0];
      int tempfend = tempcurr[1];
      int tempostart = tempcurr[2];
      int tempoend = tempcurr[3];
      char tempchar = frontstr[tempfend];
      cout << tempchar << endl;
      int index = -1;
      for (int i = ostart; i <= oend; i++) {
        if (orderstr[i] == tempchar) {
          index = i;
        }
      }
      if (tempfstart <= index - 1 && tempostart <= index - 1) {
        vector<int> temporder(4, 0);
        temporder[0] = tempfstart;
        temporder[1] = index - 1;
        temporder[2] = tempostart;
        temporder[3] = index - 1;
        qu.push(temporder);
      }
      if (index <= tempfend - 1 && index + 1 <= tempoend) {
        vector<int> temporder(4, 0);
        temporder[0] = index;
        temporder[1] = tempfend - 1;
        temporder[2] = index + 1;
        temporder[3] = tempoend;
        qu.push(temporder);
      }
    }
  }
  void sortedArrayToBST(string s1, string s2) {
    dfs(s1, s2, 0, s1.size() - 1, 0, s2.size() - 1);
  }
};
int main() {
  Solution a;
  string test1 = "CBEFDA";
  string test2 = "CBAEDF";
  a.sortedArrayToBST(test1, test2);
  return 0;
}
