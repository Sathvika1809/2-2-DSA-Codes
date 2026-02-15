#include <stdio.h>
const long long mod = 1000000007LL;
int main(){
    int n;
    scanf("%d",&n);
    long long res = 1;
    for(int i=0;i<n;i++){
        res = (res*2)%mod;
    }
    printf("%lld",res);
    return 0;
}