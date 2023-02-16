/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin() bool cmp(const word &num1, const word &num2) {
  return num1.value != num2.value ? num1.value > num2.value: num1.name <
 num2.name;} v.insert(v.begin()+3,1);####
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  queue<int> A;
  queue<int> B;
  MyStack() {}

  void push(int x) {
    B.push(x);
    while (!A.empty()) {
      int tempnum = A.front();
      B.push(tempnum);
      A.pop();
    }
    swap(A, B);
  }

  int pop() {
    int tempnum = A.front();
    A.pop();
    return tempnum;
  }

  int top() { return A.front(); }

  bool empty() { return A.empty(); }
};
int main() {
  Solution a;
  return 0;
}
