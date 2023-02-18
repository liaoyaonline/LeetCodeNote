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
  void dfs(vector<string> &res, string &Str, int i) {
    if (i == Str.size()) {
      res.push_back(Str);
      return;
    }
    for (int j = i; j < Str.size(); j++) {
      swap(Str[i], Str[j]);
      dfs(res, Str, i + 1);
      swap(Str[i], Str[j]);
    }
  }
  vector<string> permutation(string s) {
    vector<string> Result;
    set<string> Res;
    vector<string> AllResult;
    dfs(Result, s, 0);
    for (int i = 0; i < Result.size(); i++) {
      if (Res.find(Result[i]) == Res.end()) {
        Res.insert(Result[i]);
      }
    }
    for (auto it = Res.cbegin(); it != Res.cend(); it++) {
      AllResult.push_back(*it);
    }
    return AllResult;
  }
};
int main() {
  Solution a;
  string str;
  cin >> str;
  vector<string> Result = a.permutation(str);
  for (int i = 0; i < Result.size(); i++) {
    cout << Result[i] << endl;
  }
  return 0;
}
