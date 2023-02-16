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
#include <mutex>
#include <set>
#include <stack>
#include <string>
#include <thread>
#include <vector>
using namespace std;
mutex mtx;
int i = 0;
void func() {
  mtx.lock();
  cout << "进入线程!" << endl;
  ++i;
}
int main() {
  int a = 0;
  a++;
  a++;
  a++;
  a++;
  a++;
  thread t1(func);
  thread t2(func);
  t1.join();
  t2.join();
  cout << "over" << endl;
  return 0;
}
