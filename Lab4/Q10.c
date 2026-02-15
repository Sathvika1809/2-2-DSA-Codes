#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int ok(int* arr,int n,int g,int mid){
    int sum =0;
    for(int i=0;i<n;i++){
        if(arr[i]<=mid){
            sum+=arr[i];
        }else{
            int rem = arr[i]-mid;
            sum+=mid;
        }
        if(sum>=g){
            return 1;
        }
    }
    return 0;
}
int main(){
    int n,g;
    scanf("%d %d",&n,&g);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int lo = 0,hi= INT_MAX;
    int ans = -1;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(ok(arr,n,g,mid)){
            ans = mid;
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    printf("%d",ans);
    return 0;
}