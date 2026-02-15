#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int x;
    scanf("%d",&x);
    int lo = 0,hi=n-1;
    int floorans = -1;
    int ceilans = -1;
    while(lo<=hi){
        int mid= lo+(hi-lo)/2;
        if(arr[mid]<=x){
            floorans = arr[mid];
            lo = mid+1;
        }else{
            hi=mid-1;
        }
    }
    lo=0,hi=n-1;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(arr[mid]>=x){
            ceilans = arr[mid];
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    printf("%d %d",floorans,ceilans);
    return 0;
}