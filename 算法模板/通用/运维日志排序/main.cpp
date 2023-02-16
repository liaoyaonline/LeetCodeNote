/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin() bool cmp(const word &num1, const word &num2) {
  return num1.value != num2.value ? num1.value > num2.value: num1.name <
 num2.name;} v.insert(v.begin()+3,1);map.containsKey(num) s.substr(i,2)####
 */
#include <limits.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
bool cmp(vector<int> u, vector<int> v) {
  for (int i = 0; i < u.size() - 1; i++) {
    if (u[i] != v[i]) return u[i] < v[i];
  }
  return u[0] < v[0];
}
class Solution {
 public:
  vector<int> split(string s, char ch) {
    vector<int> res;
    if (s.empty()) return res;
    string tempstr = "";
    int flag = 0;
    int index = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ch) {
        flag++;
        int tempnum = atoi(tempstr.c_str());
        res.push_back(tempnum);
        tempstr = "";
        if (flag == 2) {
          index = i + 1;
          break;
        }
        continue;
      }
      tempstr.push_back(s[i]);
    }
    string backstr = s.substr(index);
    int secondindex = 0;
    for (int i = 0; i < backstr.size(); i++) {
      if (backstr[i] == '.') secondindex = i;
    }
    string firststr = backstr.substr(0, secondindex);
    string secondstr = backstr.substr(secondindex + 1);
    int tempnum2 = atoi(firststr.c_str());
    res.push_back(tempnum2);
    tempnum2 = atoi(secondstr.c_str());
    res.push_back(tempnum2);
    return res;
  }
  vector<string> minWindow(vector<string> logs) {
    vector<vector<int>> nums(logs.size());
    vector<string> result(logs.size());
    for (int i = 0; i < logs.size(); i++) {
      nums[i] = split(logs[i], ':');
      nums[i].push_back(i);
    }
    sort(nums.begin(), nums.end(), cmp);
    for (int i = 0; i < logs.size(); i++) {
      int index = nums[i][4];
      result[i] = logs[index];
    }
    return result;
  }
};
int main() {
  Solution a;
  int N;
  cin >> N;
  vector<string> test(N);
  for (int i = 0; i < N; i++) cin >> test[i];
  vector<string> test2 = a.minWindow(test);
  for (int i = 0; i < test2.size(); i++) cout << test2[i] << endl;
  return 0;
}
