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
class StockSpanner {
 public:
  vector<int> st;
  vector<int> prices;
  int i;
  StockSpanner() {
    i = 1;
    prices.push_back(100001);
    st.push_back(0);
  }
  int next(int price) {
    prices.push_back(price);
    int result = 1;
    while (!st.empty() && prices[st.back()] <= price) {
      st.pop_back();
      result = i - st.back();
    }
    st.push_back(i);
    i++;
    return result;
  }
};
int main() {
  StockSpanner* obj = new StockSpanner();
  vector<int> test{100, 80, 60, 70, 60, 75, 85};
  for (int i = 0; i < test.size(); i++) cout << obj->next(test[i]) << " ";
  cout << endl;
  return 0;
}
