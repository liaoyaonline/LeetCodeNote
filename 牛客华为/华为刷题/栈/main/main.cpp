#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
struct usr {
  string name;
  int mark;
};
bool cmp0(usr num1, usr num2) { return num1.mark > num2.mark; }
bool cmp1(usr num1, usr num2) { return num1.mark < num2.mark; }
class Solution {
 public:
  vector<usr> MarkSort(vector<usr> &usrs, int flag) {
    if (usrs.empty()) {
      return usrs;
    }
    if (flag == 0)
      sort(usrs.begin(), usrs.end(), cmp0);
    else if (flag == 1)
      sort(usrs.begin(), usrs.end(), cmp1);
    return usrs;
  }
};
int main() {
  Solution a;
  vector<usr> students;
  vector<usr> result;
  int num = 0;
  int flag = 0;
  cin >> num;
  cin >> flag;
  for (int i = 0; i < num; i++) {
    usr temp;
    cin >> temp.name;
    cin >> temp.mark;
    students.push_back(temp);
  }
  result = a.MarkSort(students, flag);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i].name << " " << result[i].mark << endl;
  }
  return 0;
}
