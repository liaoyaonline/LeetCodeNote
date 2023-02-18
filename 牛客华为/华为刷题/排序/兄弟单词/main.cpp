#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  bool IsBrother(string str1, string str2) {
    if (str1 == str2) return false;
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    if (str1 != str2) return false;
    return true;
  }
  void BrotherWord() {
    int num;
    vector<string> wordlist;
    vector<string> result;
    string word;
    int k;
    cin >> num;
    for (int i = 0; i < num; i++) {
      string tempword;
      cin >> tempword;
      wordlist.push_back(tempword);
    }
    cin >> word;
    cin >> k;
    for (int i = 0; i < wordlist.size(); i++) {
      if (IsBrother(wordlist[i], word)) {
        result.push_back(wordlist[i]);
      }
    }
    cout << result.size() << endl;
    sort(result.begin(), result.end());
    if (result.size() >= k) cout << result[k - 1] << endl;
  }
};
int main() {
  Solution a;
  a.BrotherWord();
  return 0;
}
