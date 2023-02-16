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
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
bool cmp1(int u, int v) { return u > v; }
bool cmp2(vector<int> u, vector<int> v) {
  for (int i = 0; i < u.size() - 1; i++) {
    if (u[i] != v[i]) return u[i] > v[i];
  }
  return u[0] > v[0];
}
class Solution {
 public:
  vector<int> sqit(string S, char flag) {
    vector<int> res;
    string tempstr = "";
    for (int i = 0; i < S.size(); i++) {
      if (S[i] == flag) {
        int num = atoi(tempstr.c_str());
        res.push_back(num);
        tempstr = "";
        continue;
      }
      tempstr.push_back(S[i]);
    }
    int tempnum = atoi(tempstr.c_str());
    res.push_back(tempnum);
    return res;
  }
  bool minWindow(vector<vector<int>>& nums) {
    for (int i = 0; i < nums.size(); i++) {
      sort(nums[i].begin(), nums[i].end(), cmp1);
      nums[i].push_back(i + 1);
    }
    sort(nums.begin(), nums.end(), cmp2);
    return true;
  }
};
int main() {
  Solution a;
  string test;
  cin >> test;
  vector<int> test2 = a.sqit(test, ',');
  int N = test2[1];
  int M = test2[0];
  vector<vector<int>> nums1(M, vector<int>(N, 0));
  for (int i = 0; i < M; i++) {
    string tempstr;
    cin >> tempstr;
    vector<int> tempnum = a.sqit(tempstr, ',');
    for (int j = 0; j < tempnum.size(); j++) {
      nums1[i][j] = tempnum[j];
    }
  }
  vector<vector<int>> nums2(N, vector<int>(M, 0));
  for (int i = 0; i < nums1.size(); i++) {
    for (int j = 0; j < nums1[0].size(); j++) {
      nums2[j][i] = nums1[i][j];
    }
  }
  a.minWindow(nums2);
  cout << nums2[0][nums2[0].size() - 1] << "," << nums2[1][nums2[1].size() - 1]
       << "," << nums2[2][nums2[2].size() - 1] << endl;
  return 0;
}
