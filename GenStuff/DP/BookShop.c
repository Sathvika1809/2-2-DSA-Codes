#include <stdio.h>
#include <stdlib.h>
int max(int a,int b){
    return a>b?a:b;
}
int maxPages(int* h,int n,int* s,int x){
    int dp[x+1];
    for(int i=0;i<=x;i++){
        dp[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=x;j>=s[i];j--){
            if(j-h[i]>0){
            dp[j] = max(dp[j],dp[j-h[i]]+s[i]);
        }
    }
}
    int ans =0;
    for(int i=0;i<=x;i++){
        ans = max(ans,dp[i]);
    }
    return ans;


}
int main(){
    int n,x;
    scanf("%d %d",&n,&x);
    int h[n];
    for(int i=0;i<n;i++){
        scanf("%d",&h[i]);
    }
    int s[n];
    for(int i=0;i<n;i++){
        scanf("%d",&s[i]);
    }
    int pages = maxPages(h,n,s,x);
    printf("%d\n",pages);

    return 0;
}