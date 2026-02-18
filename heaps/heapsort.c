#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//Build maxHeap and repeatedly delete elements and print them for a sorted array
void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int* arr,int n,int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n&&arr[left]>arr[largest]){
        largest = left;
    }
    if(right<n&&arr[right]>arr[largest]){
        largest = right;
    }
    if(largest!=i){
        swap(&arr[largest],&arr[i]);
        heapify(arr,n,largest);
    }
    return;
}
void buildMaxHeap(int* arr,int n){
    for(int i=(n/2)-1;i>=0;i--){
        heapify(arr,n,i);
    }
    return;
}
//Swap all the root elements with the leaf nodes so that all leaf/small nodes thing contains only max elements
void heapsort(int* arr,int n){
    for(int i=n-1;i>0;i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    buildMaxHeap(arr,n);
    heapsort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}