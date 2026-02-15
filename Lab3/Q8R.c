#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int ok(int* arr,int n,int d,int mid){
    int sum=0,cnt=1;
    for(int i=0;i<n;i++){
        if(arr[i]>mid){
            return 0;
        }
        sum+=arr[i];
        if(sum>mid){
            cnt++;
            sum = arr[i];
        }
    }
    return (cnt<=d);
}
int maxEle(int* arr,int n){
    int max = INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}
int total(int* weights,int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=weights[i];
    }
    return sum;
}
int main(){
    int n,d;
    scanf("%d %d",&n,&d);
    int weights[n];
    for(int i=0;i<n;i++){
        scanf("%d",&weights[i]);
    }
    int max = maxEle(weights,n);
    int tot = total(weights,n);
    int lo = max,hi=tot;
    int ans = 0;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(ok(weights,n,d,mid)){
            ans = mid;
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    printf("%d",ans);
    return 0;
}