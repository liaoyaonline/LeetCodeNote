#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> TwoSum(vector<int> nums, int target) {
    map<int, int> hashmap;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
      if (hashmap.find(target - nums[i]) != hashmap.end()) {
        result.push_back(hashmap[target - nums[i]]);
        result.push_back(i);
        break;
      } else {
        hashmap[nums[i]] = i;
      }
    }
    return result;
  }
};
int main() {
  Solution a;
  vector<int> Result;
  vector<int> list = {3, 2, 4};
  Result = a.TwoSum(list, 6);
  for (int i = 0; i < Result.size(); i++) {
    cout << Result[i] << endl;
  }
  return 0;
}
