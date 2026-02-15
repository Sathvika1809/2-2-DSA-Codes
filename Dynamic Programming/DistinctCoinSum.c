#include <stdio.h>
#include <stdlib.h>
const int mod = 1e9+7;
int distinct(int* c,int n,int x){
    int dp[x+1];
    for(int i=0;i<=x;i++){
        dp[i]=0;
    }
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int s=c[i];s<=x;s++){
            if(s-c[i]<0)continue;
            dp[s]=(dp[s]+dp[s-c[i]])%mod; 
        }
    }
    return dp[x];
}
int main(){
    int n,x;
    scanf("%d %d",&n,&x);
    int c[n];
    for(int i=0;i<n;i++){
        scanf("%d",&c[i]);
    }
    printf("%d\n",distinct(c,n,x));

    return 0;
}