#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
struct Interval {
  int start;
  int end;
};
bool cmp(Interval num1, Interval num2) {
  if (num1.start == num2.start) return num1.end < num2.end;
  return num1.start < num2.start;
}
class Solution {
 public:
  vector<Interval> merge(vector<Interval> &intervals) {
      if(intervals.empty())
      {
          return intervals;
      }
    sort(intervals.begin(), intervals.end(), cmp);
    vector<Interval> result;
    result.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i].start <= result.back().end &&
          intervals[i].end >= result.back().end) {
        result.back().end = intervals[i].end;
      } else if(intervals[i].start > result.back().end){
        result.push_back(intervals[i]);
      }
    }
    return result;
  }
};
int main() {
  Solution a;
  vector<Interval> inters;
  vector<Interval> result;
  for (int i = 0; i < 4; i++) {
    Interval temp;
    scanf("%d,%d", &temp.start, &temp.end);
    inters.push_back(temp);
  }
  result = a.merge(inters);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i].start << "," << result[i].end << endl;
  }
  return 0;
}
