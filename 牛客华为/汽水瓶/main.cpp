#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    int NumA[100];
    int NumB[100];
    int i = 0;
    while(1)
    {
        cin >> NumA[i];
        if(NumA[i] == 0)
            break;
        i++;
    }
    for(int i = 0; NumA[i] != 0; i++)
    {
        int tmp =(int) (NumA[i] * 1/2);
        cout << tmp << endl;
    }
}
