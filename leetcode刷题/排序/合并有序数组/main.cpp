/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin()####
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
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for (int i = 0; i < n; i++) nums1[i + m] = nums2[i];
    sort(nums1.begin(), nums1.end());
    return;
  }
};
int main() {
  Solution a;
  int test[6] = {1, 2, 3, 0, 0, 0};
  vector<int> nums1(test, test + 6);
  int test2[3] = {2, 5, 6};
  vector<int> nums2(test2, test2 + 3);
  a.merge(nums1, 3, nums2, 3);
  for (int i = 0; i < nums1.size(); i++) {
    cout << nums1[i] << " ";
  }
  return 0;
}
