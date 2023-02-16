/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin() bool cmp(const word &num1, const word &num2) {
  return num1.value != num2.value ? num1.value > num2.value: num1.name <
 num2.name;} v.insert(v.begin()+3,1);map.containsKey(num)####
 */
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
  int minimumRecolors(string blocks, int k) {
    int minnums = 7;
    int tempcount = 0;
    for (int i = 0; i < k; i++) {
      if (blocks[i] == 'W') tempcount++;
    }
    minnums = tempcount;
    for (int j = k; j < blocks.size(); j++) {
      if (blocks[j] == 'W') tempcount++;
      if (blocks[j - k] == 'W') tempcount--;
      minnums = min(minnums, tempcount);
    }
    return minnums;
  }
};
int main() {
  Solution a;
  string test = "WBBWWBBWBW";
  cout << a.minimumRecolors(test, 7) << endl;
  return 0;
}
