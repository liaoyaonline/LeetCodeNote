/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin() bool cmp(const word &num1, const word &num2) {
  return num1.value != num2.value ? num1.value > num2.value: num1.name <
 num2.name;} v.insert(v.begin()+3,1);map.containsKey(num) s.substr(i,2)####
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
struct Trie {
    map<char,Trie *> children;
};
vector<string> split(string str1, char np) {
  vector<string> result;
  string tempstr = "";
  for (int i = 0; i < str1.size(); i++) {
    if (str1[i] == np) {
      result.push_back(tempstr);
      tempstr = "";
      continue;
    }
    tempstr.push_back(str1[i]);
  }
  result.push_back(tempstr);
  return result;
}
class Solution {
 public:
     string replaceWords(vector<string>& dictionary,string sentence){
         Trie *trie = new Trie();
         for(auto &word : dictionary){
             Trie *cur = trie;
             for(char &c: word)
             {
                 if(!cur->children.count(c))
                     cur->children[c] = new Trie();
                 cur = cur->children[c];
             }
             cur->children['#'] = new Trie();
         }
         vector<string> words = split(sentence,' ');
         for(auto &word: words){
             word = findRoot(word,trie);
         }
         string ans;
         for(int i = 0; i < words.size() - 1; i++)
         {
             ans.append(words[i]);
             ans.append(" ");
         }
         ans.append(words.back());
         return ans;
     }
     string findRoot(string &word,Trie *trie){
         string root;
         Trie *cur = trie;
         for(char &c: word){
             if(cur->children.count('#')){
                 return root;
             }
             if(!cur->children.count(c)){
                 return word;
             }
             root.push_back(c);
             cur = cur->children[c];
         }
         return root;
     }
};
int main() {
  string test = "the cattle was rattled by the battery";
  Solution a;
  vector<string> test2{"cat", "bat", "rat"};
  cout << a.replaceWords(test2,test) << endl;
  return 0;
}
