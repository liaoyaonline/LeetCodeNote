#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    bool duplicate(int numbers[],int length,int* duplication)
    {
        bool flag = false;
        int *numtmp = new int[length];
        /*for(int i = 0;i < length; i++)
            numtmp[i] = 0;*/
        for(int i = 0;i < length; i++)
            numtmp[numbers[i]] ++;
        for(int i = 0;i < length; i++)
            if(numtmp[numbers[i]] > 1)
            {
                flag = true;
                *duplication = numbers[i];
                break;
            }
        return flag;
    }
};
int main()
{
    Solution a;
    int testa[] = {2,3,1,0,2,5,3};
    int test[] = {2,1,3,1,4};
    int dump;
    int *p = &dump;
    a.duplicate(testa,7,p);
    cout << *p << endl;
    a.duplicate(test,5,p);
    cout << endl;
    cout << *p << endl;
    return 0;
}

