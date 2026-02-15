#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int ans = -1;
    int lo=0,hi=n-1;
    while(lo<hi){
        int mid = lo+(hi-lo)/2;
        if(arr[mid]>arr[mid+1]){
            hi = mid;
        }else{
            lo = mid+1;
        }
    }
    printf("%d\n",lo);

    return 0;
}