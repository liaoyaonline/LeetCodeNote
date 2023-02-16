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
      if (s[i] == ',') {
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
  vector<vector<int>> minWindow(vector<int> A, vector<int> B, int R) {
    vector<vector<int>> Res;
    for (int i = 0, j = 0; i < A.size(); i++) {
      int flag = 0;
      while (A[i] > B[j] && j < B.size()) {
        j++;
      }
      for (int r = j; r < B.size(); r++) {
        if (A[i] <= B[r] && B[r] - A[i] <= R) {
          flag = 1;
          vector<int> tempnums(2, 0);
          tempnums[0] = A[i];
          tempnums[1] = B[r];
          Res.push_back(tempnums);
        }
      }
      if (flag == 0 && j < B.size()) {
        vector<int> tempnums(2, 0);
        tempnums[0] = A[i];
        tempnums[1] = B[j];
        Res.push_back(tempnums);
      }
    }
    return Res;
  }
};
int main() {
  Solution a;
  string tempstr1;
  string tempstr2;
  int R;
  cin >> tempstr1;
  cin >> tempstr2;
  cin >> R;
  vector<int> test1 = a.split(tempstr1, ',');
  vector<int> test2 = a.split(tempstr2, ',');
  vector<vector<int>> Res = a.minWindow(test1, test2, R);
  for (int i = 0; i < Res.size(); i++) {
    cout << Res[i][0] << "," << Res[i][1] << endl;
  }
  return 0;
}
