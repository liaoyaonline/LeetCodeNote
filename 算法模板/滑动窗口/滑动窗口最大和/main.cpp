/*pow(16,i),queue.front()struct Tree{};vector<string> res(8, "");mp.find(key) ==
 * mp.end() int a[5] = {},vector<int> num(a,a+..) set test; test.insert(1),auto
 * it = test.begin() bool cmp(const word &num1, const word &num2) {
  return num1.value != num2.value ? num1.value > num2.value: num1.name <
 num2.name;} v.insert(v.begin()+3,1);map.containsKey(num)####
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
  int minWindow(vector<int> nums, int M) {
    int maxsum = 0;
    for (int i = 0; i < M; i++) maxsum += nums[i];
    int tempsum = maxsum;
    for (int left = 0, right = M; right < nums.size(); right++) {
      tempsum += nums[right];
      tempsum -= nums[left];
      left++;
      maxsum = max(maxsum, tempsum);
    }
    return maxsum;
  }
};
int main() {
  Solution a;
  int N = 0;
  cin >> N;
  int M = 0;
  vector<int> test(N, 0);
  for (int i = 0; i < N; i++) {
    cin >> test[i];
  }
  cin >> M;
  cout << a.minWindow(test, M) << endl;
  return 0;
}
