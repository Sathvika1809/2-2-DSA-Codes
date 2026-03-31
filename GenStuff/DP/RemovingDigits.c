#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INF 1000000000
int min(int a,int b){
    return a<b?a:b;
}
int noofsteps(int n){
    int dp[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=INF;
    }
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        int temp = i;
        while(temp>0){
            int d = temp%10;
            if(d>0){
                dp[i]=min(dp[i],1+dp[i-d]);
            }
            temp/=10;
        }
    }
    return dp[n];
}
int main(){
    int n;
    scanf("%d",&n);
    int a = noofsteps(n);
    printf("%d\n",a);
    return 0;
}