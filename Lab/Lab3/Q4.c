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
    int lo = 0,hi = n-1;
    int ans =-1;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(arr[mid]==tgt){
            ans = mid;
        }
        if(arr[mid]<= arr[hi]){
            if(arr[mid]<=tgt && tgt<=arr[hi]){
                 lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        else{
            if(arr[mid]>=tgt && tgt>=arr[lo]){
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
    }
    free(arr);
    printf("%d\n",ans);
    return 0;
}