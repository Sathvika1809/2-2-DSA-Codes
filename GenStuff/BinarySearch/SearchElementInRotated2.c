#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int k;
    scanf("%d",&k);
    int lo=0,hi=n-1;
    int fnd = 0;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(arr[mid]==k){
            printf("true");
            fnd =1;
            break;
        }
        if(arr[lo]==arr[mid]==arr[hi]){
            lo++;
            hi--;
        }
        if(arr[lo]<=arr[mid]){
            if(arr[lo]<=k&&k<arr[mid]){
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        else{
            if(arr[mid]<k&&k<=arr[hi]){
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
    }
    if(!fnd){
        printf("false");
    }
    return 0;
}
