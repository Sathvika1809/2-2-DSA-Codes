#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//12345  //34512 //
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int lo = 0,hi=n-1;
    while(lo<hi){
        int mid = lo+(hi-lo)/2;
        if(arr[mid]>arr[hi]){
            lo = mid+1;
        }else{
            hi = mid;
        }
    }
    printf("%d\n",lo);
    //when lo meets high that index is rotation count

    return 0;
}