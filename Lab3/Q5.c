#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d",&n);
    int* arr = (int*)calloc(n,sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int tgt;
    scanf("%d",&tgt);
    int lo = 0,hi =n-1;
    int start = -1;
    int end = -1;
    int mid = 0;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(arr[mid]==tgt){
            start = mid;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    
    lo =0,hi=n-1;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(arr[mid]==tgt){
            end = mid;
            lo=mid+1;
        }else{
            hi = mid-1;
        }
    }
    printf("%d %d",start,end);
    return 0;
}