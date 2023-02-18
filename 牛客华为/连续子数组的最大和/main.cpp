#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        int j1 = 0;
        int j2 = 0;
        int nummax = array[0];
        int sumtmp = nummax;
        cout << endl;
        for(int i = 1; i < array.size();i++)
        {
            sumtmp += array[i];
            if(array[i] > sumtmp && array[i] > nummax)
            {
                nummax = array[i];
                sumtmp = nummax;
                j1 = i;
                j2 = i;
            }
            if(sumtmp > nummax)
            {
                nummax = sumtmp;
                j2 = i;
            }
        }
        return nummax;
    }
};
int main()
{
    Solution a;
    vector<int> test;
    test.push_back(6);
    test.push_back(-3);
    test.push_back(-2);
    test.push_back(7);
    test.push_back(-15);
    test.push_back(1);
    test.push_back(2);
    test.push_back(2);
    cout << a.FindGreatestSumOfSubArray(test)<< endl;
    return 0;
}

