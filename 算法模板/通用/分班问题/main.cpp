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
struct T {
  int id;
  int isyes;
};
class Solution {
 public:
  int split(vector<T>& student, string s, char C) {
    vector<string> tempstr;
    string temp = "";
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == C) {
        tempstr.push_back(temp);
        temp = "";
      }
      temp.push_back(s[i]);
    }
    tempstr.push_back(temp);
    for (int i = 0; i < tempstr.size(); i++) {
      T test;
      string tempid = tempstr[i];
      test.isyes = tempid[tempid.size() - 1];
      tempid.pop_back();
      tempid.pop_back();
      int id = atoi(tempid.c_str());
      if (id <= 0 || id > 999) return -1;
      test.id = id;
      student.push_back(test);
    }
    return 0;
  }
  vector<vector<int>> minWindow(vector<T> student) {
    vector<vector<int>> res(2);
    int flag = 0;
    res[0].push_back(student[0].id);
    for (int i = 1; i < student.size(); i++) {
      switch (student[i].isyes) {
        case 'Y':
          res[flag].push_back(student[i].id);
          break;
        case 'N':
          flag = (flag + 1) % 2;
          res[flag].push_back(student[i].id);
          break;
      }
    }
    return res;
  }
};
int main() {
  Solution a;
  vector<T> students;
  vector<vector<int>> res;
  string test;
  getline(cin, test);
  if (a.split(students, test, ' ') == -1) {
    cout << "ERROR" << endl;
    return 0;
  }
  res = a.minWindow(students);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
