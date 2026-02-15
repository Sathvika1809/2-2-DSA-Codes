#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
const int mod = 1e9+7;
int calculate(int* c,int n,int x){
    int dp[x+1];
    for(int i=0;i<=x;i++){
        dp[i]=0;
    }
    dp[0]=1;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i-c[j]>=0){
            dp[i]=(dp[i]+dp[i-c[j]])%mod;
            }
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
    printf("%d\n",calculate(c,n,x));



    return 0;
}
