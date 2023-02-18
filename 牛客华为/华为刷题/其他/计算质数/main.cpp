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
  int minPrime(int num) {
    int coutPrime = 0;
    for (int i = 0; i < num; i++) {
      if (IsPrime(i)) {
        coutPrime++;
      }
    }
    return coutPrime;
  }
};
int main() {
  Solution a;
  int num = 0;
  int Result;
  cin >> num;
  Result = a.minPrime(num);
  cout << Result << endl;
  return 0;
}
