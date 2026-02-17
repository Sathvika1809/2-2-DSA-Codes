#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int totalxor(int* arr,int n){
    int total = 0;
    for(int i=1;i<=n;i++){
        total=total^arr[i];
    }
    return total;
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n+1];
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    int total = totalxor(arr,n);
    int left = 0;
    int fnd=0;
    for(int i=2;i<=n-1;i++){
        left^=arr[i-1];
        int right = total^left^arr[i];
        if(left == right){
            printf("%d",i);
            fnd = 1;
        }
    }
    if(!fnd){
        
    }

    return 0;
}