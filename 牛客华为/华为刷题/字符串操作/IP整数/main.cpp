#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  void IPNum(void) {
    long long int a, b, c, d, num, temp;
    scanf("%lld.%lld.%lld.%lld", &a, &b, &c, &d);
    cin >> num;
    temp = (a << 24) + (b << 16) + (c << 8) + d;
    a = num >> 24;
    num -= a << 24;
    b = num >> 16;
    num -= b << 16;
    c = num >> 8;
    num -= c << 8;
    d = num;
    cout << temp << endl;
    cout << a << "." << b << "." << c << "." << d << endl;
  }
};
int main() {
  Solution a;
  a.IPNum();
  return 0;
}
