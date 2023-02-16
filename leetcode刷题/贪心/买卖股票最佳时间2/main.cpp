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
  int maxProfit(vector<int>& prices) {
    int maxsum = 0;
    int currmax = 0;
    int currmin = prices[0];
    for (int i = 1; i < prices.size(); i++) {
      if (prices[i] >= prices[i - 1]) {
        currmax = prices[i] - currmin;
      } else {
        maxsum += currmax;
        currmin = prices[i];
        currmax = 0;
      }
    }
    maxsum += currmax;
    return maxsum;
  }
};
int main() {
  Solution a;
  vector<int> test{7, 1, 5, 3, 6, 4};
  cout << a.maxProfit(test) << endl;
  return 0;
}
