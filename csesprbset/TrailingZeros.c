#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(){
    int n;
    scanf("%d",&n);
    int cnt=0;
    
    while(n>0){
        n/=5;
        cnt+=n;
    }
    printf("%d\n",cnt);

    return 0;
}