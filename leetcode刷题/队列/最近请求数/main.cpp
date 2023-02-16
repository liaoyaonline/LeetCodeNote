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
class RecentCounter {
 public:
  queue<int> requests;
  RecentCounter() {}
  int ping(int t) {
    requests.push(t);
    while (requests.front() < (t - 3000)) {
      requests.pop();
    }
    return requests.size();
  }
};
int main() {
  RecentCounter a;
  vector<int> test{1, 100, 3001, 3002};
  for (int i = 0; i < test.size(); i++) {
    cout << a.ping(test[i]) << endl;
  }
  return 0;
}
