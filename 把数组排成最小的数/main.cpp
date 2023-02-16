#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
     static bool cmp(int a , int b)
    {
        string A = "";
        string B = "";
        A += to_string(a);
        A += to_string(b);
        B += to_string(b);
        B += to_string(a);
        return A < B;
    }
    string PrintMinNumber(vector<int> numbers) {
        string answer = "";
        sort(numbers.begin(),numbers.end(),cmp);
        for(int i = 0; i < numbers.size(); i++)
            answer += to_string(numbers[i]);
        return answer;
    }
};
int main()
{
    Solution a;
    vector<int> number;
    number.push_back(321);
    number.push_back(32);
    number.push_back(3);
    number.push_back(11);
    for(auto it = number.begin();it != number.end();it++)
        cout << *it << " ";
    //a.PrintMinNumber(number);
    a.cmp(321,32);
    return 0;
}

