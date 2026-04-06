#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
void merge(int* arr,int l,int m,int r,int* ans){
    int n1 = m-l+1,n2 = r-m;
    int L[n1];
    int R[n2];
    for(int i=0;i<n1;i++){
        L[i] = arr[i+l];
    }
    for(int i=0;i<n2;i++){
        R[i] = arr[i+m+1];
    }
    int i=0,j=0,k=l;
    while(i<n1&&j<n2){
        if(L[i]>R[j]){
            *ans += n1-i;
             arr[k++] = R[j++];
        }else{
            arr[k++] = L[i++];
        }
    }
    while(i<n1){
        arr[k++] = L[i++];
    }
    while(j<n2){
        arr[k++] = R[j++];
    }

}
void mergesort(int* arr,int l,int r,int* ans){
    if(l<r){
        int mid = l+(r-l)/2;
        mergesort(arr,l,mid,ans);
        mergesort(arr,mid+1,r,ans);
        merge(arr,l,mid,r,ans);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int ans = 0;
    mergesort(a,0,n-1,&ans);
    printf("%d\n",ans);



    return 0;
}