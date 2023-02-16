#include <iostream>
#include <algorithm>
using namespace std;
class Solution{
public:
    void PrintString(string str){
        cout << str << endl;
    }
    string ReverseSentence(string str){
        if(str.size() == 0 )
            return str;
        reverse(str.begin(),str.end());
        PrintString(str);
        int n = str.size();
        for(int i = 0,j = 0; j <= n;j++)
        {
            if(str[j] == ' ' || j == n)
            {
                reverse(str.begin() + i,str.begin() + j);
                i = j+1;
            }
        }
        PrintString(str);
        return str;
    }
};
int main()
{
    string s2 = "oliming. am I world hello";
    Solution a;
    a.PrintString(s2);
    string s1 = a.ReverseSentence(s2);
    std::cout << "Hello world" << std::endl;
    return 0;
}

