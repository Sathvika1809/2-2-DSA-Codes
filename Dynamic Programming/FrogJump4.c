#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
int min(int a,int b){
    return a<b?a:b;
}
int solve(int* heights,int n,int k){
    int dp[n];
    for(int i=0;i<n;i++){
        dp[i]=-1;
    }
    dp[0]=0;
    for(int i=1;i<n;i++){
        int steps = INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int stepj = dp[i-j]+abs(heights[i]-heights[i-j]);
                steps = min(steps,stepj);
            }
        }
        dp[i] = steps;
    }
    return dp[n-1];
}
int main(){
    int heights[] = {10,5,20,0,15};
    int k;
    scanf("%d",&k);
    int n = sizeof(heights)/sizeof(heights[0]);
    int a = solve(heights,n,k);
    printf("%d\n",a);
    return 0;
}