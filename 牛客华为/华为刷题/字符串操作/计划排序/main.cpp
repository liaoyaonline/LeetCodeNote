#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
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
  void playSort(void) {
    int size = 0;
    int flag = 0;
    int nums[1000] = {0};
    cin >> size;
    for (int i = 0; i < size; i++) {
      cin >> nums[i];
    }
    cin >> flag;
    QuickSort(nums, 0, size - 1);
    if (flag == 0) {
      for (int i = 0; i < size; i++) {
        cout << nums[i] << " ";
      }
    } else {
      for (int i = size - 1; i >= 0; i--) {
        cout << nums[i] << " ";
      }
    }
  }
};
int main() {
  Solution a;
  a.playSort();
  return 0;
}
