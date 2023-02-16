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
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    map<int, int> hashmap;
    vector<int> result;
    for (int i = 0; i < nums2.size() - 1; i++) {
      for (int j = i + 1; j < nums2.size(); j++) {
        if (nums2[j] > nums2[i]) {
          hashmap[nums2[i]] = nums2[j];
          break;
        }
      }
    }
    for (int i = 0; i < nums1.size(); i++) {
      if (hashmap.find(nums1[i]) != hashmap.end()) {
        result.push_back(hashmap[nums1[i]]);
        continue;
      }
      result.push_back(-1);
    }
    return result;
  }
};
int main() {
  Solution a;
  vector<int> test1{4, 1, 2};
  vector<int> test2{1, 3, 4, 2};
  vector<int> res = a.nextGreaterElement(test1, test2);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}
