#include <iostream>
using namespace std;
#pragma pack(2)
struct A{
    //int x;
    char y;
    int b;
    short c;
    //short z;
};
#pragma pack()
int main()
{
    A a;
    //cout << sizeof(a.x) << ":" << sizeof(a.y) << ":" << sizeof(a.z) << endl;
    cout << sizeof(a) << endl;
    return 0;
}

