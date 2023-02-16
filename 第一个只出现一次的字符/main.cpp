#include <iostream>
using namespace std;
class Solution{
public:
    int FirstNotRepeatingChar(string str)
    {
        int num = -1;
        int nummark[60] = {0};
        for(int i = 0; i < str.size(); i++)
        {
            int tmp = str[i] - 'A';
            nummark[tmp] ++;
        }
        for(int i = 0; i < str.size(); i++)
        {
            int tmp = str[i] - 'A';
            if(nummark[tmp] == 1)
            {
                num = i;
                break;
            }
        }
        return num;
    }
};
int main()
{
    Solution a;
    string test = "aabbccddeeffgghhklsdjfklasjflkasjfkaus";
    cout << a.FirstNotRepeatingChar(test);
    return 0;
}

