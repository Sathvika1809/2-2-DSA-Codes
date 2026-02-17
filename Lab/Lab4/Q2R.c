#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// void bubble(int* arr,int left,int right){
//     for(int i=left;i<=right;i++){
//         int swapped=0;
//         for(int j=left;j<right-(i-left);j++){
//             if(arr[j]>arr[j+1]){
//                 int t=arr[j];
//                 arr[j]=arr[j+1];
//                 arr[j+1]=t;
//                 swapped = 1;
//             }
//         }
//         if(!swapped){
//             break;
//         }
//     }
// }
int min(int a,int b){
    return a<b?a:b;
}
void merge(int* arr,int l,int m,int r){
    int n1=m-l+1,n2=r-m;
    int L[n1],R[n2];
    for(int i=l;i<=m;i++){
        L[i-l]=arr[i];
    }
    for(int j=m+1;j<=r;j++){
        R[j-m-1]=arr[j];
    }
    int i=0,j=0,k=l;
    while(i<n1&&j<n2){
        if(L[i]<=R[j]){
            arr[k++]=L[i++];
        }else{
            arr[k++]=R[j++];
        }
    }
    while(i<n1){
        arr[k++]=L[i++];
    }
    while(j<n2){
        arr[k++]=R[j++];
    }
    return;
}
void mergesort(int* arr,int lo,int hi){
    if(lo<hi){
        int mid = lo+(hi-lo)/2;
        mergesort(arr,lo,mid);
        mergesort(arr,mid+1,hi);
        merge(arr,lo,mid,hi);
    }
    return;
}
void mergesortHelper(int* arr,int lo,int hi){
    mergesort(arr,lo,hi);
    return;
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
            mergesortHelper(arr,left,left+size-1);
            left+=size;
        }else{
            mergesortHelper(arr,right-size+1,right);
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