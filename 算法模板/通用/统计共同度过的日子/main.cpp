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
class Solution {
 public:
  vector<int> split(string s, char ch) {
    vector<int> res;
    if (s.empty()) return res;
    string tempstr = "";
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ch) {
        int tempnum = atoi(tempstr.c_str());
        res.push_back(tempnum);
        tempstr = "";
        continue;
      }
      tempstr.push_back(s[i]);
    }
    int tempnum2 = atoi(tempstr.c_str());
    res.push_back(tempnum2);
    return res;
  }
  int getday(vector<int> mdays, int mon, int day) {
    int result = 0;
    for (int i = 1; i < mon; i++) {
      result += mdays[i];
    }
    result += day;
    return result;
  }
  int minWindow(string arriveAlice, string leaveAlice, string arriveBob,
                string leaveBob) {
    int res = 0;
    vector<int> monday{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<vector<int>> startend(4, vector<int>(2, 0));
    startend[0] = split(arriveAlice, '-');
    startend[1] = split(leaveAlice, '-');
    startend[2] = split(arriveBob, '-');
    startend[3] = split(leaveBob, '-');
    vector<int> days(4, 0);
    for (int i = 0; i < 4; i++) {
      days[i] = getday(monday, startend[i][0], startend[i][1]);
    }
    if (days[0] > days[2]) {
      swap(days[0], days[2]);
      swap(days[1], days[3]);
    }
    if (days[2] > days[1]) return 0;
    if (days[3] <= days[1])
      res = days[3] - days[2] + 1;
    else
      res = days[1] - days[2] + 1;
    return res;
  }
};
int main() {
  Solution a;
  string test1 = "10-20";
  string test2 = "12-22";
  string test3 = "06-21";
  string test4 = "07-05";
  cout << a.minWindow(test1, test2, test3, test4) << endl;
  return 0;
}
