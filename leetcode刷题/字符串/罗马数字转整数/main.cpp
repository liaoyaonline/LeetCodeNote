/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end()####
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
  int romanToInt(string s) {
    int result = 0;
    for (int i = 0; i < s.size(); i++) {
      switch (s[i]) {
        case 'I':
          if (i < s.size() - 1 && s[i + 1] == 'V') {
            i++;
            result += 4;
            break;
          }
          if (i < s.size() - 1 && s[i + 1] == 'X') {
            i++;
            result += 9;
            break;
          }
          result += 1;
          break;
        case 'X':
          if (i < s.size() - 1 && s[i + 1] == 'L') {
            i++;
            result += 40;
            break;
          }
          if (i < s.size() - 1 && s[i + 1] == 'C') {
            i++;
            result += 90;
            break;
          }
          result += 10;
          break;
        case 'C':
          if (i < s.size() - 1 && s[i + 1] == 'D') {
            i++;
            result += 400;
            break;
          }
          if (i < s.size() - 1 && s[i + 1] == 'M') {
            i++;
            result += 900;
            break;
          }
          result += 100;
          break;
        case 'V':
          result += 5;
          break;
        case 'L':
          result += 50;
          break;
        case 'D':
          result += 500;
          break;
        case 'M':
          result += 1000;
          break;
      }
    }
    return result;
  }
};
int main() {
  Solution a;
  string strs;
  cin >> strs;
  cout << a.romanToInt(strs) << endl;
  return 0;
}
