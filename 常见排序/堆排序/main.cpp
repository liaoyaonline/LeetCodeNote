#include <iostream>
using namespace std;
class Solution {
 public:
     void max_heapify(int arr[],int start,int end){
         int dad = start;
         int son = dad*2 + 1;
         while(son <= end){
             if(son +1 <= end && arr[son] > arr[son + 1])
                 son ++;
             if( arr[dad] < arr[son] )
                 return;
             else{
                 swap(arr[dad],arr[son]);
                 dad = son;
                 son = dad * 2 + 1;
             }
         }
     }
  void heap_sort(int input[], int size) {
      for(int i = size / 2 -1; i >= 0; i--)
      {
          max_heapify(input,i,size-1);
      }
      for(int i = size -1; i > 0; i--){
          swap(input[0],input[i]);
          max_heapify(input,0,i-1);
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
  a.heap_sort(p, 10);
  a.PrintNum(p);
  return 0;
}
