#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int findmin(int* a,int n,int k,int lim){
    int sum =0;
    int cnt=1;
    for(int i=0;i<n;i++){
        if(a[i]>lim){
            return 0;
        }
        if(sum+a[i]>lim){
            cnt++;
            sum = a[i];
        }else{
        sum+=a[i];
        }
    }
    return cnt<=k;
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int len[n];
    for(int i=0;i<n;i++){
        scanf("%d",&len[i]);
    }
    int lo=0,hi=INT_MAX;
    int ans=0;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(findmin(len,n,k,mid)){
            ans = mid;
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    printf("%d\n",ans);
    return 0;
    
}