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
  vector<int> minPrime(int even) {
    int midnum = even / 2;
    vector<int> result;
    for (int i = midnum; i > 0; i--) {
      if (IsPrime(i) && IsPrime(even - i)) {
        result.push_back(i);
        result.push_back(even - i);
        break;
      }
    }
    return result;
  }
};
int main() {
  Solution a;
  int num = 0;
  vector<int> Result;
  cin >> num;
  Result = a.minPrime(num);
  for (int i = 0; i < Result.size(); i++) {
    cout << Result[i] << endl;
  }
  return 0;
}
