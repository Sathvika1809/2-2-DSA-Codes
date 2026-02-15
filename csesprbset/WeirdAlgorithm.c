#include <stdio.h>

int main(){
    long long n;
    scanf("%lld",&n);
    printf("%lld ",n);
    while(n!=1){
        if(n%2 == 1){
            n = n*3+1;
            printf("%lld ",n);
        }else if(n%2 == 0){
            n/=2;
            printf("%lld ",n);
        }
    }

    return 0;
}
