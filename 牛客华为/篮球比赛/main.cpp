#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
bool myfunction(int i,int j){return (i > j);}
int main() {
    int Num = 10;
    int Sum1 = 0;
    int Sum2 = 0;
    vector<int> Result;
    for(int i = 0;i < Num; i++)
    {
        int tmp;
        cin >> tmp;
        Result.push_back(tmp);
    }
    for(int i = 0; i < Num ; i++)
    {
        sort(Result.begin(),Result.end(),myfunction);
    }
    for(int i = 0,j = Num - 1; i < j;)
    {
        if(Sum1 <= Sum2)
        {
            Sum1 += Result[i];
            cout << Result[i]  << ":" << Result[j] << endl;
            Sum2 += Result[j];
            i++;
            j--;
        }
        else
        {
            Sum2 += Result[i];
            Sum1 += Result[j];
            cout << Result[i]  << ":" << Result[j] << endl;
            i++;
            j--;
        }
    }
    if(Sum1 >= Sum2)
        cout << Sum1 - Sum2 << endl;
    else
        cout << Sum2 - Sum1 << endl;
}
