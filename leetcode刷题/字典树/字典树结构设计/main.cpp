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
struct TrieNode {
  vector<TrieNode*> child;
  bool isEnd;
  TrieNode() {
    this->child = vector<TrieNode*>(26, nullptr);
    this->isEnd = false;
  }
};
void insert(TrieNode* root, const string& word) {
  TrieNode* node = root;
  for (int i = 0; i < word.size(); i++) {
    if (node->child[word[i] - 'a'] == nullptr) {
      node->child[word[i] - 'a'] = new TrieNode();
    }
    node = node->child[word[i] - 'a'];
  }
  node->isEnd = true;
}
class WordDictionary {
 public:
  WordDictionary() { trie = new TrieNode(); }
  void addWord(string word) { insert(trie, word); }
  bool search(string word) { return dfs(word, 0, trie); }
  bool dfs(const string& word, int index, TrieNode* node) {
    if (index == word.size()) {
      return node->isEnd;
    }
    char ch = word[index];
    if (ch >= 'a' && ch <= 'z') {
      TrieNode* child = node->child[ch - 'a'];
      if (child != nullptr && dfs(word, index + 1, child)) {
        return true;
      }
    } else if (ch == '.') {
      for (int i = 0; i < 26; i++) {
        TrieNode* child = node->child[i];
        if (child != nullptr && dfs(word, index + 1, child)) {
          return true;
        }
      }
    }
    return false;
  }

 private:
  TrieNode* trie;
};
int main() {
  WordDictionary a;
  a.addWord("bad");
  a.addWord("dad");
  a.addWord("mad");
  cout << a.search("pad") << endl;
  cout << a.search("bad") << endl;
  cout << a.search(".ad") << endl;
  cout << a.search("b..") << endl;
  return 0;
}
