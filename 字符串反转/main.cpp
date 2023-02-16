#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = " ";
    cin >> str;
    cout << str.size() << endl;
    cout << str << endl;
    for(int i = str.size() -1 ; i >=0 ;i--)
    {
        cout << str[i];
    }
}
