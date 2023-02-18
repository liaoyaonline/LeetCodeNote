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
  int minMultiple(int S, int T) {
    int basenum = max(S, T);
    int maxmultiple = min(S, T);
    int minmultiple = 0;
    for (int i = 1; i <= maxmultiple; i++) {
      int temp = i * basenum;
      if (temp % maxmultiple == 0) {
        minmultiple = temp;
        break;
      }
    }
    return minmultiple;
  }
};
int main() {
  Solution a;
  int firstnum;
  int secondnum;
  cin >> firstnum;
  cin >> secondnum;
  cout << a.minMultiple(firstnum, secondnum) << endl;
  return 0;
}
