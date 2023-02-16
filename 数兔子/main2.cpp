#include<iostream>
#include<vector>
using namespace std;
int main(){
    int month;
    while(cin>>month){
        if(month==1||month==2)
            {cout<<1<<endl;continue;}
        vector<int> dp(month+1,0);
        dp[1]=1;
        dp[2]=1;
        for(int i=3;i<=month;i++){
            dp[i]=dp[i-1]+dp[i-2];//i-1是上个月的，i-2的满足生育能力的（第三个月）
        }
        cout<<dp[month]<<endl;
    }
    //1 1 2 3 5 8 13 21 34
}
