#include <iostream>
using namespace std;
class Solution {
 public:
  void Bubblesort(int *input, int size) {
    for (int i = 0; i < size - 1; i++) {
      for (int j = 0; j < size - i - 1; j++) {
        if (input[j] < input[j + 1]) {
          int temp = 0;
          temp = input[j];
          *(input + j) = input[j + 1];
          *(input + j + 1) = temp;
        }
      }
    }
  }
  void CreateNum(int *nums) {
    for (int i = 0; i < 10; i++) {
      *(nums + i) = i;
    }
  }
  void PrintNum(int *nums) {
    for (int i = 0; i < 10; i++) {
      cout << *(nums + i) << " :";
    }
    cout << endl;
  }
};
int main() {
  int nums[10];
  int *p = nums;
  Solution a;
  a.CreateNum(p);
  a.PrintNum(p);
  a.Bubblesort(p, 10);
  a.PrintNum(p);
  return 0;
}
