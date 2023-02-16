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
class Solution {
 public:
  double minWindow(vector<int>& arr) {
    int n = arr.size();
    int start = n / 20;
    int end = n - start - 1;
    int sum = 0;
    int len = end - start + 1;
    sort(arr.begin(), arr.end());
    for (int i = start; i <= end; i++) sum += arr[i];
    double res = (double)sum / (double)len;
    return res;
  }
};
int main() {
  Solution a;
  vector<int> test{6,  0, 7, 0, 7, 5, 7, 8,  3, 4, 0, 7, 8, 1,
                   6,  8, 1, 1, 2, 4, 8, 1,  9, 5, 4, 3, 8, 5,
                   10, 8, 6, 6, 1, 0, 6, 10, 8, 2, 3, 4};
  cout << a.minWindow(test) << endl;
  return 0;
}
