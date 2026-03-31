#include <stdio.h>
#include <stdlib.h>
const int mod = 1e9+7;
int calculate(int n,char arr[n][n]){
    if(arr[0][0]=='*'){
        return 0;
    }
    int dp[n];
    for(int i=0;i<n;i++){
        dp[i]=0;
    }
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]=='*'){
                dp[j]=0;
            }
            else if(j>0){
            dp[j]=(dp[j]+dp[j-1])%mod;
            }
        }
    }
    return dp[n-1];

}
int main(){
    int n;
    scanf("%d",&n);
    char arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf(" %c",&arr[i][j]);
        }
    }
    printf("%d\n",calculate(n,arr));

    return 0;
}