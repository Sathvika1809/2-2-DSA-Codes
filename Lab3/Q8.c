#include <stdio.h>
int ok(int* a,int n,int d,int w){
    int sum=0;
    int cnt=1;
    for(int i=0;i<n;i++){
        if(a[i]>w)return 0;
        sum+=a[i];
        if(sum>w){
            cnt++;
            sum=a[i];
        }
    }
    return cnt<=d;
}
int main(){
    int n,d;
    scanf("%d %d",&n,&d);
    int weights[n];
    for(int i=0;i<n;i++){
        scanf("%d",&weights[i]);
    }
    int lo=1,hi=1e9;
    int ans =0;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(ok(weights,n,d,mid)){
            ans = mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    printf("%d\n",ans);
    return 0;
}