/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin() bool cmp1(usr num1, usr num2) { return a.size() != b.size()
 * ? a.size() < b.size() : a > b; }####
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
struct word {
  string name;
  int value;
};
bool cmp(const word &num1, const word &num2) {
  return num1.value != num2.value ? num1.value > num2.value
                                  : num1.name < num2.name;
}
class Solution {
 public:
  vector<string> topKFrequent(vector<string> &words, int k) {
    map<string, int> hashmap;
    vector<word> tempword;
    vector<string> result;
    for (int i = 0; i < words.size(); i++) hashmap[words[i]]++;
    for (auto it = hashmap.begin(); it != hashmap.end(); it++) {
      word temp;
      temp.name = it->first;
      temp.value = it->second;
      tempword.push_back(temp);
    }
    sort(tempword.begin(), tempword.end(), cmp);
    for (int i = 0; i < tempword.size(); i++) {
      string tempstr = tempword[i].name;
      result.push_back(tempstr);
    }
    return result;
  }
};
int main() {
  Solution a;
  vector<string> test{
      "glarko",     "zlfiwwb",    "nsfspyox",   "pwqvwmlgri", "qggx",
      "qrkgmliewc", "zskaqzwo",   "zskaqzwo",   "ijy",        "htpvnmozay",
      "jqrlad",     "ccjel",      "qrkgmliewc", "qkjzgws",    "fqizrrnmif",
      "jqrlad",     "nbuorw",     "qrkgmliewc", "htpvnmozay", "nftk",
      "glarko",     "hdemkfr",    "axyak",      "hdemkfr",    "nsfspyox",
      "nsfspyox",   "qrkgmliewc", "nftk",       "nftk",       "ccjel",
      "qrkgmliewc", "ocgjsu",     "ijy",        "glarko",     "nbuorw",
      "nsfspyox",   "qkjzgws",    "qkjzgws",    "fqizrrnmif", "pwqvwmlgri",
      "nftk",       "qrkgmliewc", "jqrlad",     "nftk",       "zskaqzwo",
      "glarko",     "nsfspyox",   "zlfiwwb",    "hwlvqgkdbo", "htpvnmozay",
      "nsfspyox",   "zskaqzwo",   "htpvnmozay", "zskaqzwo",   "nbuorw",
      "qkjzgws",    "zlfiwwb",    "pwqvwmlgri", "zskaqzwo",   "qengse",
      "glarko",     "qkjzgws",    "pwqvwmlgri", "fqizrrnmif", "nbuorw",
      "nftk",       "ijy",        "hdemkfr",    "nftk",       "qkjzgws",
      "jqrlad",     "nftk",       "ccjel",      "qggx",       "ijy",
      "qengse",     "nftk",       "htpvnmozay", "qengse",     "eonrg",
      "qengse",     "fqizrrnmif", "hwlvqgkdbo", "qengse",     "qengse",
      "qggx",       "qkjzgws",    "qggx",       "pwqvwmlgri", "htpvnmozay",
      "qrkgmliewc", "qengse",     "fqizrrnmif", "qkjzgws",    "qengse",
      "nftk",       "htpvnmozay", "qggx",       "zlfiwwb",    "bwp",
      "ocgjsu",     "qrkgmliewc", "ccjel",      "hdemkfr",    "nsfspyox",
      "hdemkfr",    "qggx",       "zlfiwwb",    "nsfspyox",   "ijy",
      "qkjzgws",    "fqizrrnmif", "qkjzgws",    "qrkgmliewc", "glarko",
      "hdemkfr",    "pwqvwmlgri"};
  vector<string> result = a.topKFrequent(test, 14);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << endl;
  }
  return 0;
}
