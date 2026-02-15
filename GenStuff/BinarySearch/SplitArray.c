#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int total(int* arr,int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}
int maxEle(int* arr,int n){
    int min = INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>min){
            min = arr[i];
        }
    }
    return min;
}
int ok(int* arr,int n,int k,int mid){
    int cnt=1,sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(arr[i]>mid){
            return 0;
        }
        if(sum>mid){
            cnt++;
            sum = arr[i];
        }
    }
    return (cnt<=k);
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int k;
    scanf("%d",&k);
    int sum = total(arr,n);
    int max = maxEle(arr,n);
    int lo =max,hi = sum;
    int ans =0;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(ok(arr,n,k,mid)){
            ans = mid;
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }

printf("%d",ans);
    return 0;
}