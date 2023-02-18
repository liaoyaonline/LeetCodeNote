#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;
class Solution {
 public:
  int HexCon(int num) {
    int res = 0;
    if(num <= 1)
        return res;
    res = num / 2;
    return res;
  }
};
int main() {
  Solution a;
  int num;
  while(1)
  {
      int num = 0;
      cin >> num;
      if(num == 0)
          break;

      cout << a.HexCon(num) << endl;
  }
  return 0;
}
