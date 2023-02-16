/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin() bool cmp(const word &num1, const word &num2) {
  return num1.value != num2.value ? num1.value > num2.value: num1.name <
 num2.name;} v.insert(v.begin()+3,1);map.containsKey(num) s.substr(i,2)####
string b= to_string(int a); int a =
atoi(b.c_str());d.emplace(d.begin()+1,4)在0后，1前面插入4
d.erase(d.begin()+1);删除1坐标上的数据*/
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
#define MOD 1000000007
class Solution {
 public:
  int lowbit(int x) { return x & (-x); }
  vector<int> minWindow(int n, vector<vector<int>>& queries) {
    vector<int> dp;
    int x = n;
    while (x) {
      int tempnum = lowbit(x);
      dp.push_back(tempnum);
      x -= tempnum;
    }
    vector<int> result(queries.size(), 1);
    for (int i = 0; i < queries.size(); i++) {
      int tempstart = queries[i][0];
      int tempend = queries[i][1];
      for (int j = tempstart; j <= tempend; j++) {
        long long int tempnum = ((long int)result[i] * (long int)dp[j]) % MOD;
        result[i] = (int)tempnum;
      }
    }
    return result;
  }
};
int main() {
  Solution a;
  vector<vector<int>> test{{5, 5}, {4, 4}, {4, 6}};
  vector<int> result = a.minWindow(919, test);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " " << endl;
  }
  cout << endl;
  return 0;
}
