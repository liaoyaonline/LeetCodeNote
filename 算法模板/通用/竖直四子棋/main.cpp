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
  bool iserror(vector<int> hashmap, int n, int Maxlen, int Maxhigh) {
    if (n <= 0 || n > Maxlen) return false;
    if (hashmap[n] >= Maxhigh) return false;
    return true;
  }
  bool iswin(vector<vector<int>> nums, int k, int x, int y) {
    int flag = nums[x][y];
    int n = nums.size() - 1;
    int m = nums[0].size() - 1;
    vector<int> win(4, 0);
    for (int i = x; i > 0; i--)  //竖直方向
    {
      if (nums[i][y] != flag) {
        break;
      }
      win[0]++;
    }
    if (win[0] >= k) return true;
    for (int i = y; i <= m; i++)  //横向
    {
      if (nums[x][i] != flag) {
        break;
      }
      win[1]++;
    }
    for (int i = y - 1; i > 0; i--) {
      if (nums[x][i] != flag) {
        break;
      }
      win[1]++;
    }
    if (win[1] >= k) return true;
    for (int i = x, j = y; i > 0 && j > 0; i--, j--)  //右上角左下角
    {
      if (nums[i][j] != flag) {
        break;
      }
      win[2]++;
    }
    for (int i = x + 1, j = y + 1; i <= n && j <= m; i++, j++) {
      if (nums[i][j] != flag) {
        break;
      }
      win[2]++;
    }
    if (win[2] >= k) return true;
    for (int i = x, j = y; i <= n && j > 0; i++, j--)  //左上角右下角
    {
      if (nums[i][j] != flag) {
        break;
      }
      win[3]++;
    }
    for (int i = x - 1, j = y + 1; i > 0 && j <= m; i--, j++) {
      if (nums[i][j] != flag) {
        break;
      }
      win[2]++;
    }
    if (win[3] >= k) return true;
    return false;
  }
  bool minWindow(vector<int> nums, int N, int M) {
    vector<vector<int>> Winnum(N + 1, vector<int>(M + 1, 0));
    vector<int> hashmap(M + 1, 0);
    for (int i = 1; i < nums.size(); i++) {
      if (iserror(hashmap, nums[i], M, N) == false) {
        string flag = ",error";
        cout << i << flag << endl;
        return false;
      }
      int mark;
      if (i % 2 == 1)
        mark = 1;
      else
        mark = 2;
      int y = nums[i];
      int x = hashmap[y] + 1;
      Winnum[x][y] = mark;
      hashmap[y]++;
      if (iswin(Winnum, 4, x, y) == true) {
        string flag;
        if (i % 2 == 1)
          flag = ",red";
        else
          flag = ",blue";
        cout << i << flag << endl;
        return true;
      }
    }
    cout << "0,draw" << endl;
    return true;
  }
};
int main() {
  Solution a;
  string temp;
  int N, M = 0;
  cin >> M;
  cin >> N;
  getline(cin, temp);
  getline(cin, temp);
  string tempstr = "";
  vector<int> test;
  test.push_back(0);
  for (int i = 0; i < temp.size(); i++) {
    if (temp[i] == ' ') {
      int num = atoi(tempstr.c_str());
      tempstr = "";
      test.push_back(num);
    }
    tempstr.push_back(temp[i]);
  }
  int num = atoi(tempstr.c_str());
  test.push_back(num);
  a.minWindow(test, N, M);
  return 0;
}
