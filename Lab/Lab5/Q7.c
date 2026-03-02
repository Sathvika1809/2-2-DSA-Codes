#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void swap(int* a,int* b){
    int t = *a;
    *a=*b;
    *b=t;
}
int partition(int* a,int lo,int hi){
    int pivot = a[lo];
    int left = lo+1,right = hi;
    while(1){
        while(left<=hi && a[left]<pivot)left++;
        while(right>=lo && a[right]>pivot)right--;
        if(left>=right)break;
        swap(&a[left],&a[right]);
    }
    swap(&a[lo],&a[right]);
    return right;
}
int findKthLargest(int* a,int n,int k){
    
    int lo = 0,hi = n-1;
    int t = n-k;
    while(1){
        int p = partition(a,lo,hi);
        if(p==t) return a[p];
        if(p<t) lo=p+1;
        else hi=p-1;
    }
    return -1;
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
    printf("%d\n",findKthLargest(arr,n,k));
    
    return 0;
}