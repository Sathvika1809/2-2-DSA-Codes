#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INF 1000000000
long long min(long long a,long long b){
    return a<b?a:b;
}
long long noofcoins(int n,long long x,int* arr){
   long long *dp = malloc((x+1) * sizeof(long long));
    dp[0]=0;
    for(int i=1;i<=x;i++){
         dp[i] = INF;
        for(int j=0;j<n;j++){
            if(i-arr[j]<0)continue;
            if(dp[i-arr[j]]!=INF){
            dp[i]=min(dp[i],dp[i-arr[j]]+1);
            }
        } 
    }
    if(dp[x]!=INF){
    return dp[x];
    }else{
        return -1;
    }
}
int main(){
    int n,x;
    scanf("%d %d",&n,&x);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("%lld",noofcoins(n,x,arr));
    return 0;
}