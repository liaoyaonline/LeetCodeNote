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
  int minWindow(vector<int>& nums) {
    vector<int> sortn = nums;
    sort(sortn.begin(), sortn.end());
    int sum = 0;
    for (int i = 0; i < sortn.size(); i = i + 2) {
      sum += sortn[i];
    }
    return sum;
  }
};
int main() {
  Solution a;
  vector<int> test{1, 4, 3, 2};
  cout << a.minWindow(test) << endl;
  return 0;
}
