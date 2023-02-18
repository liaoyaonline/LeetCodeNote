#include <iostream>
#include <bitset>
using namespace std;
int main()
{
    int a;
    int *p = &a;
    int m = 0;
    int sum =0;
    cin >> a;
    while(m < 32)
    {
        int g = *p&(1<<m);
        cout << g << endl;
        if(g!=0)
        {
            g = 1;
            sum++;
        }
        m++;
    }
    cout << sum<< endl;
    cout <<bitset<sizeof(a)*8>(a)<< endl;
    return 0;
}

