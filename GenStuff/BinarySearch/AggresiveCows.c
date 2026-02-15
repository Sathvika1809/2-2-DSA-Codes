#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void merge(int* arr,int lo,int mid,int hi){
    int n1 = mid-lo+1,n2 = hi-mid;
    int L[n1],R[n2];
    for(int i=lo;i<mid+1;i++){
       L[i-lo] = arr[i];
    }
    for(int i=mid+1;i<=hi;i++){
        R[i-mid-1]=arr[i];
    }
    int i=0,j=0,k=lo;
    while(i<n1&&j<n2){
        if(L[i]<R[j]){
            arr[k] = L[i++];
        }else if(L[i]>R[j]){
            arr[k] =R[j++];
        }else{
            arr[k] = L[i++];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k++]=L[i++];
    }
    while(j<n2){
        arr[k++]=R[j++];
    }
    
}
void mergesort(int* arr,int lo,int hi){
    if(lo<hi){
        int mid = lo+(hi-lo)/2;
        mergesort(arr,lo,mid);
        mergesort(arr,mid+1,hi);
        merge(arr,lo,mid,hi);
    }
}
int ok(int* arr,int n,int k,int mid){
    int cnt = 1;
    int lastPos = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]-lastPos>=mid){
            cnt++;
            lastPos = arr[i];
        }
        if(cnt>=k){
            return 1;
        }
    }
    return 0;
}
int maxEl(int* arr,int n){
    int max = INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}
int minEl(int* arr,int n){
    int min = INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<min){
            min = arr[i];
        }
    }
    return min;
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
    mergesort(arr,0,n-1);
    int max = maxEl(arr,n);
    int min = minEl(arr,n);
    int lo = 0,hi = max-min;
    int ans=0;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(ok(arr,n,k,mid)){
            ans = mid;
            lo =mid+1;
        }else{
            hi = mid-1;
        }
    }
    printf("%d",ans);
    return 0;
}