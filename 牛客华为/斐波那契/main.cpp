#include <iostream>
using namespace std;
class Solution {
public:
    int Fibonacci(int n) {
        if(n <= 1)
            return n;
        else
            return Fibonacci(n-1) + Fibonacci(n - 2);
    }
};
int main()
{
    Solution a;
    int n = 0;
    cin >> n;
    cout << a.Fibonacci(n) << endl;
    return 0;
}

