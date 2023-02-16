#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a,int b);
int main()
{
    int a[] = {34,12,45,77,90,11,2,4,5,55};
    sort(a,a+10,cmp);
    for(int i = 0;i < 10; i++)
        cout << a[i] << " ";
    return 0;
}
bool cmp(int a,int b)
{
    string A = "";
    string B = "";
    A += to_string(a);
    A += to_string(b);
    B += to_string(b);
    B += to_string(a);
    return A < B;
}
