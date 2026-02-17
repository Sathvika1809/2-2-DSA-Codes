#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int f(int x,int y){
    if((2*x*x*x)-(x*x)+(5*x)<=y){
        return 1;
    }
    return 0;
}
int main(){
    int y;
    scanf("%d",&y);
    int lo =0,hi = 80;
    int ans = -1;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(f(mid,y)){
            ans = mid;
            lo = mid+1;
        }else{
            hi = mid-1;
        }

    }
    printf("%d",ans);
        return 0;
}