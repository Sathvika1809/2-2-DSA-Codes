//My own implementation:)
//Insert - O(1)*O(logn)=O(logn)
//Delete/Remove top- O(1)*O(logn)=O(logn)
//Search - O(n)
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
    return;
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
        swap(&arr[i],&arr[largest]);
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
void insert(int* arr,int* n,int val){
    (*n)++;
    int i = *n-1;
    arr[i]=val;
    while(i!=0 && arr[(i-1)/2]<arr[i]){
        swap(&arr[i],&arr[(i-1)/2]);
        i=(i-1)/2;
    }
    return;
}
void delete(int* arr,int* n,int idx){
    if(idx >= *n)return;
    if(idx == (*n)-1){
        (*n)--;
        return;
    }
    arr[idx] = arr[(*n)-1];
    (*n)--;
    heapify(arr,*n,idx);
    return;
}
/*
//Recursive form 
void heapifyup(int* arr,int* n,int i){
    int p = (i-1)/2;
    if(p<0)return;
    if(arr[i]>arr[p]){
    swap(&arr[i],&arr[p]);
    }
    heapifyup(arr,n,p);
}




*/
int main(){
    int n;
    scanf("%d",&n);
    int heap[n];
    for(int i=0;i<n;i++){
        scanf("%d",&heap[i]);
    }
    buildMaxHeap(heap,n);
    for(int i=0;i<n;i++){
        printf("%d ",heap[i]);
    }
    printf("\n");
    int val;
    scanf("%d",&val);
    insert(heap,&n,val);
    for(int i=0;i<n;i++){
        printf("%d ",heap[i]);
    }
    printf("\n");
    int idx;
    scanf("%d",&idx);
    delete(heap,&n,idx);
    for(int i=0;i<n;i++){
        printf("%d ",heap[i]);
    }
    printf("\n");
    return 0;
}