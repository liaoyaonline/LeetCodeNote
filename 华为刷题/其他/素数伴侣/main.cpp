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
  bool IsPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
      if (num % i == 0) return false;
    }
    return true;
  }
  bool find(int num, vector<int>& evens, vector<bool>& used,
            vector<int>& match) {
    for (int i = 0; i < evens.size(); i++) {
      if (IsPrime(num + evens[i]) && !used[i]) {
        used[i] = true;
        if (match[i] == 0 || find(match[i], evens, used, match)) {
          match[i] = num;
          return true;
        }
      }
    }
    return false;
  }
  int PartnerPrime(vector<int> even, vector<int> odd) {
    int countnum = 0;
    vector<int> match(even.size(), 0);
    if (even.empty() || odd.empty()) return 0;
    for (int i = 0; i < odd.size(); i++) {
      vector<bool> used(even.size(), false);
      if (find(odd[i], even, used, match)) countnum++;
    }
    return countnum;
  }
};
int main() {
  Solution a;
  int num = 0;
  vector<int> nums;
  vector<int> even;
  vector<int> odd;
  cin >> num;
  for (int i = 0; i < num; i++) {
    int tempnum = 0;
    cin >> tempnum;
    nums.push_back(tempnum);
  }
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] % 2 == 0)
      even.push_back(nums[i]);
    else
      odd.push_back(nums[i]);
  }
  cout << a.PartnerPrime(even, odd) << endl;
  return 0;
}
