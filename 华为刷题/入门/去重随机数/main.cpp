#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> Remove(vector<int> nums) {
    vector<int> result;
    int SingleNum[1001] = {0};
    for (int i = 0; i < nums.size(); i++) {
      SingleNum[nums[i]] = 1;
    }
    for (int i = 0; i < 1001; i++) {
      if (SingleNum[i] == 1) {
        result.push_back(i);
      }
    }
    return result;
  }
};
int main() {
  Solution a;
  vector<int> Result;
  vector<int> list;
  int size = 0;
  cin >> size;
  for (int i = 0; i < size; i++) {
    int tmpnum = 0;
    cin >> tmpnum;
    list.push_back(tmpnum);
  }
  Result = a.Remove(list);
  for (int i = 0; i < Result.size(); i++) {
    cout << Result[i] << endl;
  }
  return 0;
}
