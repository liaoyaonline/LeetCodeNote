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
  int maxProfit(vector<int>& prices) {
    int minprice = prices[0];
    int maxget = 0;
    for (int i = 0; i < prices.size(); i++) {
      minprice = min(prices[i], minprice);
      if (prices[i] > minprice) maxget = max(maxget, (prices[i] - minprice));
    }
    return maxget;
  }
};
int main() {
  Solution a;
  int num[6] = {7, 1, 5, 3, 6, 4};
  vector<int> nums(num, num + 6);
  cout << a.maxProfit(nums) << endl;
  return 0;
}
