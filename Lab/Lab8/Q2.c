#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int heap[MAX];
int sz = 0;
void swap(int* a,int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
void heapifyUp(int idx){
    if(idx<=0)return;
    int parent = (idx-1)/2;
    if(heap[parent]>heap[idx]){
        swap(&heap[parent],&heap[idx]);
        heapifyUp(parent);
    }
    return;
}
void heapifyDown(int idx){
    if(2*idx+1>=sz)return;
    int left = 2*idx+1;
    int right = 2*idx+2;
    int smallest = left;
    if(right<sz&&heap[right]<heap[left]){
        smallest = right;
    }
    if(heap[idx]>heap[smallest]){
        swap(&heap[idx],&heap[smallest]);
        heapifyDown(smallest);
    }
    return;
}
void buildMinHeap(int* a,int n ){
    sz = n;
    for(int i=(n/2)-1;i>=0;i--){
        heapifyDown(i);
    }
}
void insert(int val){
    heap[sz++] = val;
    heapifyUp(sz-1);
}
int removeMin(){
    int totalCost  = 0;
    while(sz>1){
    int min1 = heap[0];
    heap[0] = heap[sz-1];
    sz--;
    heapifyDown(0);
    int min2 = heap[0];
    heap[0] = heap[sz-1];
    heapifyDown(0);
    sz--;
    int val = min1+min2;
    totalCost+=val;
    insert(val);
    }
    return totalCost;
}
int main(){
    int n;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        scanf("%d",&heap[i]);
    }
    buildMinHeap(heap,n);
    int a = removeMin();
    printf("%d ",a);

    return 0;
}