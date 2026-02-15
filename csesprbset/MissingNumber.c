#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    long long sum = 0;
    for(int i=0;i<n-1;i++){
        long long x;
        scanf("%lld",&x);
        sum+=x;
    }
    long long tot = (long long)n*(n+1)/2;
    long long num = tot-sum;
    printf("%lld ",num);

    return 0;
}
