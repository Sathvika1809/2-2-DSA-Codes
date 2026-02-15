#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void bubble(int* arr,int left,int right){
    for(int i=left;i<=right;i++){
        int swapped=0;
        for(int j=left;j<right-(i-left);j++){
            if(arr[j]>arr[j+1]){
                int t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
                swapped = 1;
            }
        }
        if(!swapped){
            break;
        }
    }
}
int min(int a,int b){
    return a<b?a:b;
}
void findIncreasingSize(int* arr,int n){
    int left=0;
    int right=n-1;
    int size=0;
    int k=1;
    int takeFromFront = 1;
    while(left<=right){
        size=min(k,right-left+1);
        if(takeFromFront){
            bubble(arr,left,left+size-1);
            left+=size;
        }else{
            bubble(arr,right-size+1,right);
            right-=size;
        }
        takeFromFront=(!takeFromFront);
        k++;
    }
    return;
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    findIncreasingSize(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}