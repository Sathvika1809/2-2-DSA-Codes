#include <stdio.h>
#include <stdlib.h>
int square(int mid,int k){
    return mid*mid<=k;
}

int main(){
    int k;
    scanf("%d",&k);
    int lo = 0,hi=1000;
    int ans = 0;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(square(mid,k)){
            ans = mid;
            lo=mid+1;
        }else{
            hi = mid-1;
        }
    }
    printf("%d\n",ans);

return 0;
}