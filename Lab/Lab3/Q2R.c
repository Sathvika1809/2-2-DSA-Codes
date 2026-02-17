#include <stdio.h>
#include <stdlib.h>
int findMax(int* arr,int n){
    int lo=1,hi=n-2;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1]){
            return mid;
            break;
        }else if(arr[mid-1]>arr[mid]){
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    return -1;
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int a = arr[0];
    int b = arr[n-1];
    printf("%d\n",findMax(arr,n));
    return 0;
}