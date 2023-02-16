/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) == mp.end()
 * int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto it = test.begin()####
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
  bool FullStr(int nums[], string T) { return true; }
  string minWindow(string S, string T) {
    int left = 0;
    int minlen = 2;
    return S.substr(left, minlen);
  }
};
int main() {
  Solution a;
  string str2;
  cin >> str2;
  string strs;
  cin >> strs;
  cout << a.minWindow(strs, str2) << endl;
  return 0;
}
