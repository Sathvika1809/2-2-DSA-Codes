#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//Optimised version of Selection sort
//We have to find max Element and swap with last element
//Binary Heap allows access in O(logn) instead of O(n)
//Overall heap sort achieves nlogn tc
//All indices from (n/2)to n-1 are LeafNodes(satisfy Heap Property)
//In MaxHeap parent>=left,right ->heapify(arr,n,i)->assumes left and right are already heaps and i is violating heap property
//bottom up property works because we know that leaf nodes are already heaps so we are taking last non leaf node (n/2-1)to be violating the heap property
//And fix from that to first element






void swap(int* a,int* b){
    int temp = *a;
    *a=*b;
    *b=temp;
    return;
}

void heapify(int* arr,int n,int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n&&arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n&&arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(&arr[largest],&arr[i]);
        heapify(arr,n,largest);
    }
    return;
}
void heapsort(int* arr,int n){
    for(int i=n-1;i>0;i--){
        swap(&arr[i],&arr[0]);
        heapify(arr,i,0);
    }
    return;
}
void buildMaxHeap(int* arr,int n){
    for(int i=(n/2)-1;i>=0;i--){
        heapify(arr,n,i);
    }
    heapsort(arr,n);
    return;
}
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

    return 0;
}