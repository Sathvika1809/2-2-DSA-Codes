#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//Problem F
int UpperBound(int* arr,int st,int end,int tgt){
    int ans = end+1;
    int l=st,r=end;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(arr[mid]>tgt){
            ans = mid;
            r = mid-1;
        }else{
           l = mid+1;
        }
    }
    return ans;
}
void problemF(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int k=0;
    int i=0;
    while(i<n){
        k++;
        int tgt = arr[i];
        i = UpperBound(arr,i,n-1,tgt);
    }
    printf("%d\n",k);
    return;
}
int lowerBound(int* arr,int n,int k){
    int lo = 0,hi=n-1;
    int ans = -1;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(arr[mid]<=k){
            ans = arr[mid];
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }
    return ans;
}
void problemG(){
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("%d\n",lowerBound(arr,n,k));
}
void problemH(){
    int n;
    scanf("%d",&n);
    int lo = 0,hi = n;
    int ans = n;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(mid*mid<=n){
            ans = mid;
            lo = mid+1;
        }else{
             hi = mid-1;
        }
    }
    printf("%d\n",ans);
    return ;
}
long long S(long long k,long long n){
    return (k*n)-(k*(k+1)/2);
}
void badSearch(){
    long long n;
    scanf("%lld",&n);
    long long half =n*(n-1)/4;
    long long lo = 1,hi=n;
    long long ans = 0;
    while(lo<=hi){
        long long mid = lo+(hi-lo)/2;
        if(S(mid,n)>=half){
            ans = mid;
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    printf("%d",ans);
    return ;
}
int ok(int* arr,int n,int k,int mid){
    long long cnt=0;
    for(int i=0;i<n;i++){
        int a = arr[i];
        cnt+=(a)/mid;
    }
    return cnt>=k;
}
int maxEle(int* arr,int n){
    int max = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int max = maxEle(arr,n);
    int lo = 1,hi=max;
    int ans =0;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(ok(arr,n,k,mid)){
            ans = mid;
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }
    printf("%d\n",ans);
    return 0;
}