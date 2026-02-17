//Logic if right rotated at some pt then at some pt 
//the array will be sorted on both sides

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
    int tgt;
    scanf("%d",&tgt);
    int lo=0,hi=n-1;
    int fnd=0;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(arr[mid]==tgt){
            fnd =1;
            printf("%d\n",mid);
            break;
        }
        if(arr[lo]<=arr[mid]){
            if(arr[lo]<=tgt&&tgt<arr[mid]){
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        else{
            if(arr[mid]<tgt&&tgt<=arr[hi]){
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
    }
    if(!fnd){
        printf("-1\n");
    }

    return 0;
}