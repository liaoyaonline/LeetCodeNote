#include <iostream>
using namespace std;
int tuzi(int p)
{
    if(p <= 2)
        return 1;
    else
        return tuzi(p-1) + tuzi(p-2);
}
int main() {
    int month;
    while(cin >> month)
    {
        cout << tuzi(month)<< endl;    
    }
}
