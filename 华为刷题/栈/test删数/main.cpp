#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  int DelNum(queue<int>& num) {
    int result = 0;
    queue<int> nums = num;
    for (int i = 0;; i++) {
      if (nums.empty()) return result;
      int tempnum = nums.front();
      result = tempnum;
      nums.pop();
      if (i % 3 != 2) nums.push(tempnum);
    }
    result = nums.front();
    return result;
  }
};
int main() {
  Solution a;
  queue<int> nums;
  int num = 0;
  cin >> num;
  for (int i = 0; i < num; i++) {
    int temp;
    nums.push(i);
  }
  cout << a.DelNum(nums) << endl;
  return 0;
}
