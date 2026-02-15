#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(){
    int n;
    scanf("%d",&n);
    int nums[n];
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    int k;
    scanf("%d",&k);
    int lo=0,hi=n-1;
    int ans =-1;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(nums[mid]==k){
            ans = mid;
            break;
        }
        if(nums[lo]<=nums[mid]){
        if(nums[lo]<=k&&k<nums[mid]){
            hi = mid-1;
        }else{
            lo = mid+1;
        }
        }
        else{
            if(nums[mid]<k&&k<=nums[hi]){
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }

    }
    printf("%d",ans);


    return 0;
}