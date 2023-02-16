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
  int value;
  TrieNode() {
    this->child = vector<TrieNode*>(26, nullptr);
    this->value = 0;
  }
};
void insert(TrieNode* root, const string& word) {  //插入单词
  TrieNode* node = root;
  for (int i = 0; i < word.size(); i++) {
    if (node->child[word[i] - 'a'] == nullptr) {
      node->child[word[i] - 'a'] = new TrieNode();
    }
    node = node->child[word[i] - 'a'];
    node->value++;
  }
}
class WordDictionary {
 public:
  WordDictionary() { trie = new TrieNode(); }
  void addWord(string word) { insert(trie, word); }
  int search(string word) {
    int sum = 0;
    dfs(word, 0, sum, trie);
    return sum;
  }
  void dfs(const string& word, int index, int& sum, TrieNode* node) {
    if (index == word.size()) {
      return;
    }
    char ch = word[index];
    if (ch >= 'a' && ch <= 'z') {
      TrieNode* child = node->child[ch - 'a'];
      if (child != nullptr) {
        sum += child->value;  //累加value值
        dfs(word, index + 1, sum, child);
      }
    }
  }

 private:
  TrieNode* trie;
};
int main() {
  WordDictionary a;
  a.addWord("abc");
  a.addWord("ab");
  a.addWord("bc");
  a.addWord("b");
  cout << a.search("abc") << endl;
  cout << a.search("ab") << endl;
  cout << a.search("bc") << endl;
  cout << a.search("b") << endl;
  return 0;
}
