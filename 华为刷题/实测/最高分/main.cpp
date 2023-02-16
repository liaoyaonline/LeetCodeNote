/*pow(16,i),queue.front()struct Tree{};####
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
int student[100000];
int checkstudent(int start, int end) {
  int maxnum = student[start];
  for (int i = start; i <= end; i++) {
    maxnum = max(student[i], maxnum);
  }
  return maxnum;
}
void updata(int sub, int newdata) { student[sub] = newdata; }
int main() {
  int n, m;
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &student[i]);
    }
    char order;
    int a, b;
    for (int i = 0; i < m; i++) {
      scanf("%c%d%d", &order, &a, &b);
      if (order == 'U') {
        updata(a, b);
      } else if (order == 'Q') {
        if (a > b) swap(a, b);
        printf("%d\n", checkstudent(a, b));
      }
    }
  }
  return 0;
}
