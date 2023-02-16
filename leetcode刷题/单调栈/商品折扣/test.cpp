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
      stack<int> st;
      st.push(0);
      for(int i = 1; i < prices.size(); i ++)
      {
          while(!st.empty() && prices[i] <= prices[st.top()])
          {
              prices[st.top()] -= prices[i];
              st.pop();
          }
          st.push(i);
      }
    return prices;
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
