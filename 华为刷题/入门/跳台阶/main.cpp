#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  int jumpFloor(int number) {
    if (number <= 2) return number;
    return jumpFloor(number - 1) + jumpFloor(number - 2);
  }
};
int main() {
  Solution a;
  int num = 0;
  int size = 0;
  cin >> num;
  size = a.jumpFloor(num);
  cout << size << endl;
  return 0;
}
