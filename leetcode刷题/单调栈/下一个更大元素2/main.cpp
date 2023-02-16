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
  vector<int> minWindow(vector<int>& nums) {
    vector<int> result;
    vector<int> st;
    vector<int> tempnums = nums;
    map<int, int> hashmap;
    for (int i = 0; i < nums.size(); i++) tempnums.push_back(nums[i]);
    for (int i = tempnums.size() - 1; i >= 0; i--) {
      if (!st.empty() && tempnums[i] < st.back()) {
        hashmap[i] = st.back();
        st.push_back(tempnums[i]);
        continue;
      }
      while (!st.empty() && tempnums[i] >= st.back()) {
        st.pop_back();
      }
      if (!st.empty() && tempnums[i] < st.back()) {
        hashmap[i] = st.back();
        st.push_back(tempnums[i]);
        continue;
      }
      st.push_back(tempnums[i]);
    }
    for (int i = 0; i < nums.size(); i++) {
      if (hashmap.find(i) != hashmap.end()) {
        result.push_back(hashmap[i]);
        continue;
      }
      result.push_back(-1);
    }
    return result;
  }
};
int main() {
  Solution a;
  vector<int> test{1, 2, 3, 4, 3};
  vector<int> result = a.minWindow(test);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  cout << endl;
  return 0;
}
