#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
long long functionimp(int x);
int findLargest(int n,int mid){
    long long y = functionimp(mid);
    if(y<=n){
       return 1;
    }
    return 0;
}
long long functionimp(int lx){
    long long x = (long long)lx;
    long long y = 2*((x*x)*x)-(x*x)+(5*x);
    return y;
}
int main(){
    long long n;
    scanf("%lld",&n);
    int lo=0,hi=1000000;
    int ans = 0;
    while(lo<=hi){
        int mid =lo+(hi-lo)/2;
        if(findLargest(n,mid)){
            ans = mid;
            lo = mid+1;
        }else{
            hi=mid-1;
        }
    }
    printf("%d\n",ans);
    return 0;

}