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
  int maxlennum(vector<int>& nums) {
    int maxlen = 1;
    for (int i = 0, j = 0; j < nums.size(); j++) {
      if (i == j) continue;
      if (j > i && nums[j] > nums[j - 1])
        maxlen = max(maxlen, (j - i + 1));
      else if (j > i && nums[j] <= nums[j - 1])
        i = j;
    }
    return maxlen;
  }
};
int main() {
  Solution a;
  vector<int> num;
  for (int i = 0; i < 5; i++) {
    int temp;
    cin >> temp;
    num.push_back(temp);
  }
  cout << a.maxlennum(num) << endl;
  return 0;
}
