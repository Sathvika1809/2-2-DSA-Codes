#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    for(long long k=1;k<=n;k++){
    long long total = (k*k)((k*k)-1)/2;
    long long attack = 0;
    if(k>=3){
        attack = 4*(k-1)*(k-2);
    }
    cout<<total-attack<<"\n";
}

    return 0;
}
