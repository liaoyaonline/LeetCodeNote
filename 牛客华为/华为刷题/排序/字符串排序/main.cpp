#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  void StrSort() {
    int num;
    vector<string> wordlist;
    cin >> num;
    for (int i = 0; i < num; i++) {
      string tempword;
      cin >> tempword;
      wordlist.push_back(tempword);
    }
    sort(wordlist.begin(), wordlist.end());
    for (int i = 0; i < wordlist.size(); i++) {
      cout << wordlist[i] << endl;
    }
  }
};
int main() {
  Solution a;
  a.StrSort();
  return 0;
}
