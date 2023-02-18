#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
public:
    static bool cmp(int a,int b)
    {
        return a < b;
    }
    vector<int> GetLeastNumbers_Solution(vector<int> input,int k)
    {
        sort(input.begin(),input.end(),cmp);
        vector<int> answer;
        if(k <= input.size())
        {
            for(int i = 0; i < k; i++)
            {
                answer.push_back(input[i]);
            }
        }
        return answer;
    }
};
int main()
{
    Solution a;
    vector<int> number;
    int k;
    number.push_back(321);
    number.push_back(36);
    number.push_back(456);
    number.push_back(44);
    number.push_back(12);
    number.push_back(76);
    number.push_back(2);
    number.push_back(45);
    number.push_back(23);
    a.GetLeastNumbers_Solution(number,3);
    return 0;
}

