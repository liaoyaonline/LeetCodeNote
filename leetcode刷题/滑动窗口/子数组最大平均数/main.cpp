/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin() bool cmp(const word &num1, const word &num2) {
  return num1.value != num2.value ? num1.value > num2.value: num1.name <
 num2.name;} v.insert(v.begin()+3,1);map.containsKey(num)####
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
  double findMaxAverage(vector<int>& nums, int k) {
    int sum = 0;
    for (int i = 0; i < k; i++) {
      sum += nums[i];
    }
    int maxsum = sum;
    for (int i = 0; i < nums.size() - k; i++) {
      sum += nums[i + k];
      sum = sum - nums[i];
      maxsum = max(sum, maxsum);
    }
    double result = (double)maxsum / k;
    return result;
  }
};
int main() {
  Solution a;
  vector<int> test{1, 12, -5, -6, 50, 3};
  cout << a.findMaxAverage(test, 4) << endl;
  return 0;
}
