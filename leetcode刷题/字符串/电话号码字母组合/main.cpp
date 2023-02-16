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
  vector<string> result;
  void dfs(int index, string s, map<char, string> hashmap, string& path) {
    if (index == s.size()) {
      result.push_back(path);
      return;
    }
    string tempstr = hashmap[s[index]];
    for (int i = 0; i < tempstr.size(); i++) {
      path.push_back(tempstr[i]);
      dfs(index + 1, s, hashmap, path);
      path.pop_back();
    }
  }
  vector<string> letterCombinations(string digits) {
    map<char, string> hashmap;
    string path = "";
    hashmap['2'] = "abc";
    hashmap['3'] = "def";
    hashmap['4'] = "ghi";
    hashmap['5'] = "jkl";
    hashmap['6'] = "mno";
    hashmap['7'] = "pqrs";
    hashmap['8'] = "tuv";
    hashmap['9'] = "wxyz";
    if (digits.empty()) return result;
    dfs(0, digits, hashmap, path);
    return result;
  }
};
int main() {
  Solution a;
  string strs;
  cin >> strs;
  vector<string> res = a.letterCombinations(strs);
  for (int i = 0; i < res.size(); i++) cout << res[i] << endl;
  return 0;
}
