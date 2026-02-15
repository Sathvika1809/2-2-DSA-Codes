#include <stdio.h>
#include <stdlib.h>


void merge(int* arr,int l,int m,int r){
    int L[m-l+1];
    int R[r-m];
    for(int i=l;i<=m;i++){
        L[i-l]=arr[i];
    }
    for(int i=m+1;i<=r;i++){
        R[i-m-1] = arr[i];
    }
    int i=0,j=0,k=l;
    while(i<m-l+1&&j<r-m){
        if(L[i]<R[j]){
            arr[k++]=L[i++];
        }else if(L[i]>R[j]){
            arr[k++]=R[j++];
        }else{
            arr[k++]=R[j++];
            i++;
        }
    }
    while(i<m-l+1){
        arr[k++]=L[i++];
    }
    while(j<r-m){
        arr[k++]=R[j++];
    }
    free(L);
    free(R);
}
void mergesort(int* arr,int l,int r){
    if(l<r){
        int m = l+(r-l)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
     scanf("%d",&arr[i]);
    }
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}