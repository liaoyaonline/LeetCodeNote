#include <iostream>
using namespace std;
struct A{
    char a;
    int b;
    short c;
};
int main()
{
    A a;
    cout << sizeof(a.a) << ":" <<sizeof(a.b) << ":" << sizeof(a.c) << endl;
    cout << sizeof(a) << endl;
    return 0;
}
