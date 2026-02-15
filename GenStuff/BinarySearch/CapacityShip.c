#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int max(int* arr,int n){
    int maxele = INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>maxele){
            maxele = arr[i];
        }
    }
    return maxele;
}
int total(int* arr,int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}
int ok(int* arr,int n,int lim,int d){
    int sum=0;
    int cnt=1;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(arr[i]>lim){
            return 0;
        }
        if(sum>lim){
            cnt++;
            sum = arr[i];
        }
    }
    return cnt<=d;
}
int main(){
    int n;
    scanf("%d",&n);
    int weights[n];
    for(int i=0;i<n;i++){
        scanf("%d",&weights[i]);
    }
    int d;
    scanf("%d",&d);
    int maxele = max(weights,n);
    int sum = total(weights,n);
    int lo = maxele,hi=sum;
    int ans=0;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(ok(weights,n,mid,d)){
            ans = mid;
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    printf("%d",ans);
    return 0;
}