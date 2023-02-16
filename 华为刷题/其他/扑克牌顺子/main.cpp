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
  bool IsContinuous(vector<int> numbers) {
    int sum = 0;
    int zeronums = 0;
    sort(numbers.begin(), numbers.end());
    for (int i = 0; i < numbers.size(); i++) {
      if (numbers[i] == 0) zeronums++;
    }
    for (int i = 0; i + 1 < numbers.size(); i++) {
      if (numbers[i] != 0 && numbers[i] == numbers[i + 1]) return false;
      if (numbers[i] != 0) sum += (numbers[i + 1] - numbers[i] - 1);
    }
    if (sum <= zeronums)
      return true;
    else
      return false;
  }
};
int main() {
  Solution a;
  vector<int> nums;
  for (int i = 0; i < 5; i++) {
    int temp;
    cin >> temp;
    nums.push_back(temp);
  }
  cout << a.IsContinuous(nums) << endl;
  return 0;
}
