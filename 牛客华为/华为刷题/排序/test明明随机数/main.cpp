#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> RandomNum(vector<int> nums) {
    vector<int> Result;
    if (nums.empty()) return Result;
    sort(nums.begin(), nums.end());
    int temp = nums[0];
    Result.push_back(temp);
    for (int i = 1; i < nums.size(); i++) {
      if (temp != nums[i]) {
        Result.push_back(nums[i]);
        temp = nums[i];
      }
    }
    return Result;
  }
};
int main() {
  vector<int> nums;
  vector<int> result;
  Solution a;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int tempnum;
    cin >> tempnum;
    nums.push_back(tempnum);
  }
  result = a.RandomNum(nums);
  for (int i = 0; i < result.size(); i++) cout << result[i] << endl;
  return 0;
}
