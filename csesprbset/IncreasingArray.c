#include <stdio.h>
long long findMinMoves(long long* arr,int n){
    long long ans = 0;
    int left =0;
    int right = n-1;
    while(left<right){
        int j = left+1;
        if(arr[left]>arr[j]){
            while(arr[j] != arr[left]){
                arr[j]=arr[j]+1;
                ans++;
            }
            left++;
        }else{
            left++;
        }
    }
    return ans;  
}
int main(){
    int n;
    scanf("%d ",&n);
    long long arr[n];
    for(long long i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    printf("%lld ",findMinMoves(arr,n));
    return 0;
}