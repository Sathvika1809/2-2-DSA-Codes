#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
int ok(int* a,int n,int h,int x){
    int cnt = 0;
    for(int i=0;i<n;i++){
        cnt+=(a[i]+x-1)/x;
    }
    return (cnt<=h);
}
int main(){
    int n;
    int h;
    scanf("%d %d",&n,&h);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int low = 1;
    int high = INT_MAX;
    int ans = 0;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(ok(a,n,h,mid)){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    printf("%d ",ans);
    printf("\n");
    return 0;
}