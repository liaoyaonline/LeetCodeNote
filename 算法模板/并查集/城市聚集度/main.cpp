/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin() bool cmp(const word &num1, const word &num2) {
  return num1.value != num2.value ? num1.value > num2.value: num1.name <
 num2.name;} v.insert(v.begin()+3,1);map.containsKey(num) s.substr(i,2)####
queue<pair<TreeNode*,int>> que;que.emplace(root,1);
*/
#include <limits.h>

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
  vector<int> nums;

 public:
  DisJointSetUnion(int n) {
    for (int i = 0; i < n + 1; i++) {
      parent.push_back(i);
      rank.push_back(1);
      nums.push_back(0);
    }
  }

  int find(int x) {
    if (x == parent[x])
      return x;
    else {
      return find(parent[x]);
    }
  }

  void merge(int x, int y) {
    int rx = find(x);
    int ry = find(y);

    if (rx != ry) {
      if (rank[rx] < rank[ry]) {
        parent[x] = y;
      }
      if (rank[rx] > rank[ry]) {
        parent[y] = x;
      }

      if (rank[rx] == rank[ry]) {
        rank[rx] += 1;
        parent[y] = x;
      }
    }
  }
  int getnums(int x) {
    if (x == parent[x])
      return x;
    else {
      nums[parent[x]]++;
      return getnums(parent[x]);
    }
  }
  int deletedp(int x) {
    vector<int> dp;
    for (int i = 1; i < parent.size(); i++) {
      if (x != i && parent[i] == x) {
        dp.push_back(nums[i] + 1);
      }
    }
    if (find(x) != x) {
      int tempnum = find(x);
      dp.push_back(nums[tempnum] - nums[x]);
    }
    sort(dp.begin(), dp.end());
    return dp[dp.size() - 1];
  }
};
class Solution {
 public:
  vector<int> findCircleNum(vector<vector<int>>& edges, int N) {
    int n = edges.size();
    DisJointSetUnion uf(N);
    vector<vector<int>> dp(N + 1, vector<int>(2, 0));
    vector<int> res;
    for (int i = 0; i < n; i++) {  //城市合并
      uf.merge(edges[i][0], edges[i][1]);
    }
    dp[0][0] = 0;
    dp[0][1] = INT_MAX;
    for (int i = 1; i <= N; i++)
      uf.getnums(i);  //计算以该节点为最终节点其城市数目
    for (int i = 1; i <= N; i++) {  //计算删除掉各个城市后其各自的dp值
      dp[i][1] = uf.deletedp(i);
      dp[i][0] = i;
    }
    sort(dp.begin(), dp.end(),
         [](vector<int> u, vector<int> v) { return u[1] < v[1]; });
    for (int i = 0; i < dp.size(); i++) {
      if (dp[i][1] != dp[0][1]) break;
      res.push_back(dp[i][0]);
    }
    return res;
  }
};
int main() {
  Solution a;
  int K = 0;
  cin >> K;
  vector<vector<int>> test(K - 1, vector<int>(2, 0));
  for (int i = 0; i < K - 1; i++) {
    cin >> test[i][0];
    cin >> test[i][1];
  }
  vector<int> res = a.findCircleNum(test, K);
  for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
  cout << endl;
  return 0;
}
