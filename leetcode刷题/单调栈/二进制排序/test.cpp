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
  int secondsToRemoveOccurrences(string s) {
    int ans = 0;
    string result = s;
    while (true) {
      vector<int> tempnum;
      for (int i = 0; i < result.size() - 1; i++) {
        if (result.substr(i, 2) == "01") {
          tempnum.push_back(i);
        }
      }
      if (tempnum.empty())
        break;
      for (int i = 0; i < tempnum.size(); i++) {
          int index = tempnum[i];
        swap(result[index], result[index + 1]);
      }
      ans++;
    }
    return ans;
  }
};
int main() {
  Solution a;
  string test = "0110101";
  cout << a.secondsToRemoveOccurrences(test) << endl;
  return 0;
}
