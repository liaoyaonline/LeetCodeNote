#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
bool myfunction(int i,int j){return (i > j);}
int main() {
    int Num;
    map<int,vector<int>> Result;
    map<int,int> Result2;
    vector<int> Result3;
    map<int,int>::iterator it;
    cin >> Num;
    int A[100][100];
    int People[100];
    for(int i = 0;i < Num; i++)
    {
        int tmp = 0;
        char tmp2 ='1';
        cin >> tmp;
        People[i] = tmp;
        if(i >= Num-1)
            break;
        cin >> tmp2;
    }
    for(int i = 0; i < Num; i++)
    {
        int tmp = 0;
        char tmp2 ='1';
        cin  >> tmp;
        Result[People[i]].push_back(tmp);
        if(i >= Num-1)
            break;
        cin >> tmp2;
    }
    for(int i = 0; i < Num ; i++)
    {
        sort(Result[People[i]].begin(),Result[People[i]].end(),myfunction);
    }
    for(int i = 0; i < Num; i++)
    {
        int sum = 0;
        if(Result[People[i]].size() < 3)
            continue;
        for(int j = 0; j < 3; j++)
        {
            sum += Result[People[i]][j];
        }
        Result2[People[i]] = sum;
    }
    for(auto it = Result2.begin(); it != Result2.end(); it++)
    {
        int tmp1 = it->first;
        int tmp2 = (it->second * 10) + tmp1;
        Result3.push_back(tmp2);
    }
    for(int i = 0; i < Num ; i++)
    {
        sort(Result3.begin(),Result3.end(),myfunction);
    }
    for(int i = 0; i < Result3.size(); i++)
    {
        int tmp1 = (int)(Result3[i] / 10);
        int tmp3 = Result3[i] - (tmp1*10);
        char tmp4 = ',';
        cout << tmp3;
        if( i >= Result3.size() -1)
            break;
        cout << tmp4;
    }


}
