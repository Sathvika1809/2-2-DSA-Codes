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
    if(n==1){
        printf("%d",arr[0]);
    }
    if(arr[0]!=arr[1]){
        printf("%d",arr[0]);
        return 0;
    }
    if(arr[n-2]!=arr[n-1]){
        printf("%d",arr[n-1]);
        return 0;
    }
    int lo=1,hi=n-2;
    int ans =-1;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(arr[mid]!=arr[mid+1]&&arr[mid]!=arr[mid-1]){
            ans = arr[mid];
            break;
        }
        if((mid%2==0 && arr[mid]==arr[mid+1])||(mid%2==1 && arr[mid]==arr[mid-1])){
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
      
    }
    printf("%d\n",ans);

    return 0;
}
