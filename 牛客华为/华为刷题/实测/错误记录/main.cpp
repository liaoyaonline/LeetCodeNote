/*pow(16,i),queue.front()####
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
string getfilepath(string path) {
  string result = "";
  for (int i = path.size() - 1; i >= 0; i--) {
    if (path[i] == '\\') break;
    result = path[i] + result;
  }
  if (result.size() > 16) result = result.substr(result.size() - 16, 16);
  return result;
}
int main() {
  vector<string> result(8, "");
  map<string, int> hashmap;
  int index = 0;
  string paths;
  string num;
  while (cin >> paths >> num) {
    string tempstr = getfilepath(paths);
    tempstr = tempstr + " " + num;
    if (hashmap.find(tempstr) == hashmap.end()) {
      hashmap[tempstr] = 1;
      result[index] = tempstr;
      index = (index + 1) % 8;
    } else
      hashmap[tempstr]++;
  }
  for (int i = 0; i < 8; i++) {
    if (result[index] != "")
      cout << result[index] << " " << hashmap[result[index]] << endl;
    index = (index + 1) % 8;
  }
  return 0;
}
