/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin() bool cmp(const word &num1, const word &num2) {
  return num1.value != num2.value ? num1.value > num2.value: num1.name <
 num2.name;}####
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
bool cmp(string str1, string str2) {
  return str1.size() != str2.size() ? str1.size() < str2.size() : str1 > str2;
}
class Solution {
 public:
  string longestWord(vector<string>& words) {
    sort(words.begin(), words.end(), cmp);
    string longestword = "";
    map<string, int> hashmap;
    hashmap[longestword] = 1;
    for (int i = 0; i < words.size(); i++) {
      string tempstr = words[i];
      tempstr.pop_back();
      if (hashmap[tempstr] == 1) {
        string tempword = words[i];
        hashmap[tempword] = 1;
        longestword = tempword;
      }
    }
    return longestword;
  }
};
int main() {
  Solution a;
  vector<string> words{"a", "banana", "app", "appl", "ap", "apply", "apple"};
  cout << a.longestWord(words) << endl;
  return 0;
}
