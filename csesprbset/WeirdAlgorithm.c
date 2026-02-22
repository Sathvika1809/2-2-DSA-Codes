#include <stdio.h>

int main(){
    long long n;
    scanf("%lld",&n);
    printf("%d ",n);
    while(n!=1){
       n= n%2==0?n/2:3*n+1;
       printf("%d ",n);
    }
    return 0;
}
