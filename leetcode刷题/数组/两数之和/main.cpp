/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() vector<string> s = split(str,'/')####
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
  vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> hashmap;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
      int tempnum = target - nums[i];
      if (hashmap.find(tempnum) != hashmap.end()) {
        result.push_back(hashmap[tempnum]);
        result.push_back(i);
        break;
      }
      hashmap[nums[i]] = i;
    }
    return result;
  }
};
int main() {
  Solution a;
  vector<int> test;
  test.push_back(3);
  test.push_back(3);
  vector<int> res = a.twoSum(test, 6);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << endl;
  }
  return 0;
}
