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
  vector<int> path;
  void dfs(int n, int k, int startIndex) {
    if (k == path.size()) {
      result.push_back(path);
      return;
    }
    for (int i = startIndex; i <= n; i++) {
      path.push_back(i);
      dfs(n, k, i + 1);
      path.pop_back();
    }
  }
  vector<vector<int>> combine(int n, int k) {
    dfs(n, k, 1);
    return result;
  }
};
int main() {
  Solution a;
  int n;
  cin >> n;
  int k;
  cin >> k;
  vector<vector<int>> Result = a.combine(n, k);
  for (int i = 0; i < Result.size(); i++) {
    for (int j = 0; j < k; j++) {
      cout << Result[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
