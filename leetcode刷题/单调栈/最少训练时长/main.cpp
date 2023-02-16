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
class Solution {
 public:
  int minWindow(int initialEnergy, int initialExperience, vector<int>& energy,
                vector<int>& experience) {
    int countnum = 0;
    int tempEnergy = initialEnergy;
    int tempExperience = initialExperience;
    for (int i = 0; i < energy.size(); i++) {
      if (energy[i] >= tempEnergy) {
        countnum += (energy[i] - tempEnergy + 1);
        tempEnergy = energy[i] + 1;
      }
      if (experience[i] >= tempExperience) {
        countnum += (experience[i] + 1 - tempExperience);
        tempExperience = experience[i] + 1;
      }
      tempEnergy = tempEnergy - energy[i];
      tempExperience = tempExperience + experience[i];
    }
    return countnum;
  }
};
int main() {
  Solution a;
  vector<int> test1{1, 4, 3, 2};
  vector<int> test2{2, 6, 3, 1};
  cout << a.minWindow(5, 3, test1, test2) << endl;
  return 0;
}
