#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int ok(int* arr,int n,int k,int mid){
    int cnt = 1;
    int lastPos = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]-lastPos>=mid){
            cnt++;
            lastPos = arr[i];
        }
        if(cnt>=k){
            return 1;
        }
    }
    return 0;
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int ans = 0;
    int lo = 0,hi=INT_MAX;
    while(lo<hi){
        int mid = lo+(hi-lo)/2;
        if(ok(arr,n,k,mid)){
            ans = mid;
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }
    printf("%d\n",ans);
    return 0;
}