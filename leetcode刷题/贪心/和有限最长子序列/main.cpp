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
  vector<int> minWindow(vector<int>& nums, vector<int>& queries) {
    int n = queries.size();
    vector<int> res(n, 0);
    sort(nums.begin(), nums.end());
    int sum = 0;
    int r = nums.size();
    vector<int> tnums = nums;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
    }
    for (int i = 0; i < queries.size(); i++) {
      while (r < nums.size() && queries[i] > sum) {
        sum += nums[r];
        tnums.push_back(nums[r]);
        r++;
      }
      while (!tnums.empty() && queries[i] < sum) {
        sum = sum - tnums.back();
        tnums.pop_back();
        r--;
      }
      res[i] = tnums.size();
    }
    return res;
  }
};
int main() {
  Solution a;
  vector<int> test1{4, 5, 2, 1};
  vector<int> test2{3, 10, 21};
  vector<int> result = a.minWindow(test1, test2);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << "";
  }
  cout << endl;
  return 0;
}
