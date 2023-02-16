/*pow(16,i),queue.front()####
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
  string charstr(string S) {
    int nums[128] = {0};
    string result = "";
    for (int i = 0; i < S.size(); i++) {
      int temp = (int)S[i];
      if (nums[temp] == 0) {
        nums[temp] = 1;
        result += S[i];
      }
    }
    return result;
  }
};
int main() {
  Solution a;
  vector<string> result;
  string str2;
  while (cin >> str2) {
    string str1 = a.charstr(str2);
    cout << str1 << endl;
  }
  return 0;
}
