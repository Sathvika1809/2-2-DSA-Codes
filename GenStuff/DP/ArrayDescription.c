#include <stdio.h>
#include <stdlib.h>

int cntArrays(int* arr,int n,int m){
    int dp[n];
    int newdp[m];
    for(int i=0;i<n;i++){
        dp[i]=0;
    }
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i]==0){
                if(abs(j-arr[i+1])<=1&&abs(j-arr[i-1])<=1){
                    dp[j]
                }
            }
        }
    }
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }


    return 0;
}