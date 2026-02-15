#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void bubble(int* arr,int n){
    for(int i=0;i<n;i++){
        int swapped  = 0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
                swapped = 1;
            }
        }
        if(!swapped){
            break;
        }
    }
}
int findKthLargest(int* arr,int n,int k){
    int pivot 
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int k;
    scanf("%d",&k);
    //bubble(arr,n);

    return 0;
}