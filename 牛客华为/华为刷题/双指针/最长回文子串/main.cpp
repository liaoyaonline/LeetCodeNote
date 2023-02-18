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
  int FullMax(string& s, int begin, int end) {
    while (begin >= 0 && end < s.size() && s[begin] == s[end]) {
      end++;
      begin--;
    }
    return end - begin - 1;
  }
  int maxlennum(string A) {
    int maxlen = 1;
    for (int i = 0; i < A.size() - 1; i++) {
      maxlen = max(maxlen, max(FullMax(A, i, i), FullMax(A, i, i + 1)));
    }
    return maxlen;
  }
};
int main() {
  Solution a;
  string strs;
  cin >> strs;
  cout << a.maxlennum(strs) << endl;
  return 0;
}
