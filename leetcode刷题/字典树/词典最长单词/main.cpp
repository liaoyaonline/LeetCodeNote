/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin() bool cmp(const word &num1, const word &num2) {
  return num1.value != num2.value ? num1.value > num2.value: num1.name <
 num2.name;} v.insert(v.begin()+3,1);map.containsKey(num) s.substr(i,2)####
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
  string minWindow(vector<string>& words) {
    vector<string> input = words;
    map<string, int> hashmap;
    string result = "";
    hashmap[result] = 1;
    sort(input.begin(), input.end(), cmp);
    for (int i = 0; i < input.size(); i++) {
      string tempstr = input[i];
      string temptest = tempstr;
      temptest.pop_back();
      if (hashmap.find(temptest) != hashmap.end()) {
        hashmap[tempstr] = 1;
        result = tempstr;
      }
    }
    return result;
  }
};
int main() {
  Solution a;
  vector<string> test{"a", "banana", "app", "appl", "ap", "apply", "apple"};
  cout << a.minWindow(test) << endl;
  return 0;
}
