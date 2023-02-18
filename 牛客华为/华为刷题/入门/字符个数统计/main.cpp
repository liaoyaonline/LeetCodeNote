#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  int Remove(string str) {
    int result = 0;
    int nums[128] = {0};
    for (int i = 0; i < str.size(); i++) {
      nums[(int)str[i]] = 1;
    }
    for (int i = 0; i < 128; i++) {
      if (nums[i] == 1) {
        result++;
      }
    }
    return result;
  }
};
int main() {
  Solution a;
  string str;
  getline(cin, str);
  int size = 0;
  size = a.Remove(str);
  cout << size << endl;
  return 0;
}
