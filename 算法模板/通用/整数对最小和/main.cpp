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
  int minWindow(vector<int> nums1, vector<int> nums2, int k) {
    vector<int> test;
    int res = 0;
    for (int i = 0; i < nums1.size(); i++) {
      for (int j = 0; j < nums2.size(); j++) {
        test.push_back(nums1[i] + nums2[j]);
      }
    }
    sort(test.begin(), test.end());
    for (int i = 0; i < k; i++) res += test[i];
    return res;
  }
};
int main() {
  Solution a;
  int N = 0;
  int M = 0;
  int k = 0;
  cin >> N;
  vector<int> test1(N, 0);
  for (int i = 0; i < N; i++) {
    cin >> test1[i];
  }
  cin >> M;
  vector<int> test2(M, 0);
  for (int i = 0; i < M; i++) cin >> test2[i];
  cin >> k;
  cout << a.minWindow(test1, test2, k) << endl;
  return 0;
}
