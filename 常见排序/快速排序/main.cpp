#include <iostream>
using namespace std;
class Solution {
 public:
  int Paritition(int arr[], int left, int right) {
    int pivot = arr[left];
    while (left < right) {
      while (left < right && arr[right] >= pivot) {
        right--;
      }
      arr[left] = arr[right];
      while (left < right && arr[left] <= pivot) {
        left++;
      }
      arr[right] = arr[left];
    }
    arr[left] = pivot;
    return left;
  }
  void QuickSort(int input[], int start, int end) {
    if (start < end) {
      int pivot = Paritition(input, start, end);
      QuickSort(input, start, pivot - 1);
      QuickSort(input, pivot + 1, end);
    }
  }
  void CreateNum(int *nums) {
    for (int i = 0, j = 10; i < 10; i++, j--) {
      *(nums + i) = j;
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
  a.QuickSort(nums, 0, 9);
  a.PrintNum(p);
  return 0;
}
