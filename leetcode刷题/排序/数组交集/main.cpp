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
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    map<int, int> hashmap;
    vector<int> res;
    set<int> tempnum;
    for (int i = 0; i < nums1.size(); i++) {
      hashmap[nums1[i]] = 1;
    }
    for (int i = 0; i < nums2.size(); i++) {
      if (hashmap[nums2[i]] == 1) tempnum.insert(nums2[i]);
    }
    for (auto it = tempnum.begin(); it != tempnum.end(); it++)
      res.push_back(*it);
    return res;
  }
};
int main() {
  Solution a;
  vector<int> Result;
  int b1[10] = {4, 9, 5};
  int b2[10] = {9, 4, 9, 8, 4};
  vector<int> nums1(b1, b1 + 3);
  vector<int> nums2(b2, b2 + 5);
  Result = a.intersection(nums1, nums2);
  for (int i = 0; i < Result.size(); i++) cout << Result[i] << " ";
  return 0;
}
