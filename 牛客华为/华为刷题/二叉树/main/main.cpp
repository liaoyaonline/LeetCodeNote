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
  bool FullStr(int nums[], string T) {
    for (int i = 0; i < T.size(); i++) {
      if (nums[(int)T[i]] < 0) return false;
    }
    return true;
  }
  string minWindow(string S, string T) {
    int right = -1;
    int left = -1;
    int minlen = S.size() + 1;
    int nums[128] = {0};
    for (int i = 0; i < T.size(); i++) {
      int temp = (int)T[i];
      nums[temp]--;
    }
    for (int start = 0, end = 0; end < S.size(); end++) {
      nums[(int)S[end]]++;
      while (FullStr(nums, T)) {
        if (minlen > (end - start + 1)) {
          minlen = end - start + 1;
          right = end;
          left = start;
        }
        int temp = (int)S[start];
        nums[temp]--;
        start++;
      }
    }
    if (left == -1) return "";
    return S.substr(left, minlen);
  }
};
int main() {
  Solution a;
  string strs;
  string str2;
  cin >> strs;
  cin >> str2;
  cout << a.minWindow(strs, str2) << endl;
  return 0;
}
