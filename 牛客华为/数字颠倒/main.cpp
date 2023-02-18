#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    int x;
    string str = " ";
    cin >> x;
    stringstream ss;
    ss << x;
    ss >> str;
    for(int i = str.size() -1 ; i >= 0; i--)
    {
        cout << str[i] ;
    }
}
