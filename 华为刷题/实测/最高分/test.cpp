#include <stdio.h>
#include <algorithm>
using namespace std;
 
const int MAXN=100000;
 
int data[MAXN+5];
 
int querymax ( int l , int r ) {
    int ans=data[l];
    for(int i=l+1;i<=r;i++) ans=max(ans,data[i]);
    return ans;
}
 
void update(int idx,int value){
    data[idx]=value;
}
 
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=n;i++){
            scanf("%d",&data[i]);
        }
        char order;
        int a,b;
        for(;m--;){
            scanf(" %c%d%d",&order,&a,&b);
            if(order=='U'){
                update(a,b);
            }else if(order=='Q'){
                if(a>b)swap(a,b);
                printf("%d\n",querymax(a,b));
            }
        }
    }
    return 0;
}
