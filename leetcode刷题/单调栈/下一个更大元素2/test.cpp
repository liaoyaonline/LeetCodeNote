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
    int n = nums.size();
      vector<int> result(n,-1);
    vector<int> st;
    for(int i = 0; i < n * 2 - 1; i++)
    {
        while(!st.empty() && nums[st.back()] < nums[i % n])
        {
            result[st.back()] = nums[i % n];
            st.pop_back();
        }
        st.push_back(i % n);
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
