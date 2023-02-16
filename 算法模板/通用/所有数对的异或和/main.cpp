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
class Solution {
 public:
  int minWindow(vector<int>& nums1, vector<int>& nums2) {
    int len1 = nums1.size();
    int len2 = nums2.size();
    if (len1 % 2 == 0 && len2 % 2 == 0) return 0;
    if (len1 % 2 == 0 && len2 % 2 != 0) {
      int sum = 0;
      for (int i = 0; i < len1; i++) {
        sum = nums1[i] ^ sum;
      }
      return sum;
    }
    if (len1 % 2 != 0 && len2 % 2 == 0) {
      int sum = 0;
      for (int i = 0; i < len2; i++) {
        sum = nums2[i] ^ sum;
      }
      return sum;
    }
    if (len1 % 2 != 0 && len2 % 2 != 0) {
      int sum = 0;
      for (int i = 0; i < len1; i++) {
        sum = nums1[i] ^ sum;
      }
      for (int i = 0; i < len2; i++) {
        sum = nums2[i] ^ sum;
      }
      return sum;
    }
    return 0;
  }
};
int main() {
  Solution a;
  vector<int> test1{2, 1};
  vector<int> test2{10, 2, 5, 0};
  cout << a.minWindow(test1, test2) << endl;
  return 0;
}
