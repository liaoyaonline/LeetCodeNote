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
  vector<int> finalPrices(vector<int>& prices) {
    map<int, int> hashmap;
    vector<int> result;
    for (int i = 0; i < prices.size() - 1; i++) {
      for (int j = i + 1; j < prices.size(); j++) {
        if (j > i && prices[j] <= prices[i]) {
          hashmap[i] = prices[j];
          break;
        }
      }
    }
    for (int i = 0; i < prices.size(); i++) {
      int tempnum = prices[i] - hashmap[i];
      result.push_back(tempnum);
    }
    return result;
  }
};
int main() {
  Solution a;
  vector<int> test{8, 4, 6, 2, 3};
  vector<int> res = a.finalPrices(test);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}
