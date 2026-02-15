#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int findFirstOccur(int* arr,int n,int tgt){
    int lo=0,hi=n-1;
    int ans = -1;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(arr[mid]==tgt){
            ans = mid;
            hi = mid-1;
        }else if(arr[mid]<tgt){
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }
    return ans;
}
int findLastOccur(int* arr,int n,int tgt){
    int lo=0,hi=n-1;
    int ans=-1;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(arr[mid]==tgt){
            ans = mid;
            lo = mid+1;
        }else if(arr[mid]<tgt){
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }
    return ans;
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int tgt;
    scanf("%d",&tgt);
    int a = findFirstOccur(arr,n,tgt);
    int b = findLastOccur(arr,n,tgt);
    printf("%d %d",a,b);
    return 0;
}
