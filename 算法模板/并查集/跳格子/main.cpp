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

  bool merge(int x, int y) {
    int rx = find(x);
    int ry = find(y);

    if (rx != ry) {
      parent[ry] = rx;
    } else {
      return false;
    }
    return true;
  }
};
class Solution {
 public:
  bool minwindows(vector<vector<int>>& nums, int n) {
    DisJointSetUnion uf(n);
    for (int i = 0; i < nums.size(); i++) {
      if (uf.merge(nums[i][0], nums[i][1]) == false) {
        return false;
      }
    }
    return true;
  }
};
int main() {
  Solution a;
  int N;
  cin >> N;
  vector<vector<int>> test{{1, 0}, {1, 2}};
  if (a.minwindows(test, 4)) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
  return 0;
}
