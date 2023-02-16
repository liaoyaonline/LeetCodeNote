#include <iostream>
using namespace std;
struct A{
    char a;
    int b;
};
int main()
{
    A a;
    cout << sizeof(a) << endl;
    cout << (void *)&(a.a) << ":" << (void *)&(a.b) << endl;
    return 0;
}
