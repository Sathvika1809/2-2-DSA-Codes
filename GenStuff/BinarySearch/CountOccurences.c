#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int main(){
    int n;
    scanf("%d",&n);
    int firstcnt=0;
    int lastcnt=0;
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int x;
    scanf("%d",&x);
    int lo=0,hi=n-1;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(arr[mid]==x){
            firstcnt++;
            lo = mid+1;
        }else if(arr[mid]>x){
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    lo = 0,hi=n-1;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(arr[mid]==x){
            lastcnt++;
            hi =mid-1;
        }else if(arr[mid]<x){
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }
    int cnt = firstcnt+lastcnt;
    printf("%d",cnt);

    return 0;
}
