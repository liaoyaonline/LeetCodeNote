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
bool cmp(vector<int> u, vector<int> v) { return u[0] > v[0]; }
class Solution {
 public:
  vector<int> minWindow(vector<int>& nums, vector<int>& queries) {
    vector<vector<int>> tempqu;
    int n = queries.size();
    vector<int> res(n, 0);
    sort(nums.begin(), nums.end());
    int sum = 0;
    for (int i = 0; i < queries.size(); i++) {
      vector<int> tempnum;
      tempnum.push_back(queries[i]);
      tempnum.push_back(i);
      tempqu.push_back(tempnum);
    }
    sort(tempqu.begin(), tempqu.end(),
         [](vector<int> u, vector<int> v) { return u[0] > v[0]; });
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
    }
    for (int i = 0; i < tempqu.size(); i++) {
      while (!nums.empty() && tempqu[i][0] < sum) {
        sum = sum - nums.back();
        nums.pop_back();
      }
      tempqu[i][2] = nums.size();
    }
    for (int i = 0; i < tempqu.size(); i++) {
      res[tempqu[i][1]] = tempqu[i][2];
    }
    return res;
  }
};
int main() {
  Solution a;
  vector<int> test1{4, 5, 2, 3};
  vector<int> test2{1};
  vector<int> result = a.minWindow(test1, test2);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << "";
  }
  cout << endl;
  return 0;
}
