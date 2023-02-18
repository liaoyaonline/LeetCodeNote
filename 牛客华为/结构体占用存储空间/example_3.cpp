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
    cout << sizeof(a) << endl;
    cout << (void *)&(a.a) << ":" << (void *)&(a.b) << ":" << (void *)&(a.c) << endl;
    return 0;
}
