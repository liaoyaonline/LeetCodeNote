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
  int minWindow(vector<int>& players, vector<int>& trainers) {
    int res = 0;
    int n = players.size();
    int m = trainers.size();
    sort(players.begin(), players.end());
    sort(trainers.begin(), trainers.end());
    for (int i = n - 1, j = m - 1; i >= 0 && j >= 0; i--) {
      if (players[i] <= trainers[j]) {
        res++;
        j--;
      }
    }
    return res;
  }
};
int main() {
  Solution a;
  vector<int> test1{4, 7, 9};
  vector<int> test2{8, 2, 5, 8};
  cout << a.minWindow(test1, test2) << endl;
  return 0;
}
