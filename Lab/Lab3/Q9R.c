#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void merge(int* arr,int low,int mid,int high,int* ans){
    int n1 = mid-low+1;
    int n2 = high-mid;
    int L[n1];
    int R[n2];
    for(int i=low;i<=mid;i++){
        L[i-low] = arr[i];
    }
    for(int i=mid+1;i<=high;i++){
        R[i-mid-1]=arr[i];
    }
    int i=0,j=0,k=low;
    while(i<mid-low+1 && j<high-mid){
        if(L[i]<=R[j]){
            arr[k++]=L[i++];
        }else{
            *ans += (mid-low+1-i);
            arr[k++]=R[j++];
        }
    }
    while(i<mid-low+1){
        arr[k++]=L[i++];
    }
    while(j<high-mid){
        arr[k++]=R[j++];
    }
}
void mergesort(int* arr,int lo,int hi,int* ans){
    if(lo<hi){
        int mid = lo+(hi-lo)/2;
        mergesort(arr,lo,mid,ans);
        mergesort(arr,mid+1,hi,ans);
        merge(arr,lo,mid,hi,ans);
    }
}
void mergesortHelper(int* arr,int n,int* ans){
    mergesort(arr,0,n-1,ans);
}

void findInversions(int* arr,int n,int* ans){
    mergesortHelper(arr,n,ans);
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    int ans =0;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    findInversions(arr,n,&ans);
    printf("%d",ans);
    return 0;
}