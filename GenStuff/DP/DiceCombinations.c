/*Logic:
to make sum x
the last dice roll could be:
1->previous sum = x-1;
2->prev sum = x-2
so on...
6->sum = x-6
*/
#include <stdio.h>
const long long mod = 1e9+7;
long long ways(int n){
    long long dp[n+1];
    for(long long i=0;i<=n;i++){
        dp[i]=0;
    }
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(i-j<0) break;
            dp[i]=(dp[i]+dp[i-j])%mod;
        }
    }
    return dp[n];
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%lld",ways(n));


    return 0;
}