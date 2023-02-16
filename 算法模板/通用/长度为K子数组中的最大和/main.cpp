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
  long long getwindow(vector<int>& nums, map<int, int>& hashmap, int& start,
                      int k) {
    long long sum = 0;
    map<int, int> temphashmap;
    hashmap = hashmap;
    for (int i = start, j = start; j < nums.size(); j++) {
      if (hashmap[nums[j]] != 0) {
        i = j;
        j--;
        map<int, int> temp;
        hashmap = temp;
        sum = 0;
        continue;
      }
      hashmap[nums[j]]++;
      sum += nums[j];
      if (hashmap.size() == k) {
        return sum;
      }
    }
    return 0;
  }
  long long minWindow(vector<int>& nums, int k) {
    int i = 0;
    map<int, int> hashmap;
    long long sum = getwindow(nums, hashmap, i, k);
    int j = i + k;
    long long maxsum = sum;
    for (; j < nums.size(); j++) {
      hashmap[nums[i]]--;
      sum -= (long long)nums[i];
      if (hashmap[nums[j]] != 0) {
        int start = j;
        sum = getwindow(nums, hashmap, start, k);
        if (sum == 0) return maxsum;
        maxsum = max(maxsum, sum);
        i = start;
        j = i + k - 1;
        continue;
      }
      sum += (long long)nums[j];
      hashmap[nums[j]]++;
      i++;
      maxsum = max(maxsum, sum);
    }
    return maxsum;
  }
};
int main() {
  Solution a;
  vector<int> test{1, 5, 4, 2, 9, 9, 9, 9, 9};
  cout << a.minWindow(test, 3) << endl;
  // a.minWindow();
  return 0;
}
