/*
Type 0 min Heap
Type1 max Heap
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
void swap(int* a,int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int* heap,int idx,int* sz,int type){
    if(type==0){
        //min Heap parent<child
    if(idx<=0)return;
    int parent = (idx-1)/2;
    if(heap[parent]>heap[idx]){
        swap(&heap[parent],&heap[idx]);
        heapifyUp(heap,parent,sz,type);
    }
    }
    else if(type == 1){
        if(idx<=0)return;
        //max heap - parent>child
        int parent = (idx-1)/2;
        if(heap[parent]<heap[idx]){
            swap(&heap[parent],&heap[idx]);
            heapifyUp(heap,parent,sz,type);
        }
    }
    return;
}
    
void heapifyDown(int* heap,int idx,int* sz,int type){
    if(type==0){
        if(idx+1>=*sz)return;
        if(2*idx+1>=*sz)return;
        int left = 2*idx+1;
        int smallest = left;
        if(2*idx+2<*sz&&heap[2*idx+2]<heap[smallest]){
            smallest = 2*idx+2;
        }
        if(heap[smallest]<heap[idx]){
            swap(&heap[smallest],&heap[idx]);
            heapifyDown(heap,smallest,sz,type);
        }
    }else if(type == 1){
        //max Heap
        if(idx+1>=*sz)return;
        if(2*idx+1>=*sz)return;
        int left = 2*idx+1;
        int largest = left;
        if(2*idx+2<*sz&&heap[2*idx+2]>heap[largest]){
            largest = 2*idx+2;
        }
        if(heap[largest]>heap[idx]){
            swap(&heap[largest],&heap[idx]);
            heapifyDown(heap,largest,sz,type);
        }
    }
    return;
}

void insert(int* heap,int* sz,int val,int type){
    heap[*sz] = val;
    *sz = *sz+1;
    heapifyUp(heap,*sz-1,sz,type);
    
    return;
}
int removeMin(int* heap,int* sz,int type){
    int val = heap[0];
    heap[0] = heap[*sz-1];
    *sz = *sz-1;
    heapifyDown(heap,0,sz,type);
    return val;
}
int main(){
    int n;
    scanf("%d",&n);
    int minHeap[MAX];
    int maxHeap[MAX];
    int minsz = 0;
    int maxsz = 0;
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    float av = a[0];
    printf("%.2f ",av);
    insert(minHeap,&minsz,a[0],0);
    for(int i=1;i<n;i++){
        if(a[i]>minHeap[0]){
            insert(minHeap,&minsz,a[i],0);
        }else{
            insert(maxHeap,&maxsz,a[i],1);
        }

        if(minsz>1+maxsz){
            int a = removeMin(minHeap,&minsz,0);
            insert(maxHeap,&maxsz,a,1);
        }else if(maxsz>1+minsz){
            int a = removeMin(maxHeap,&maxsz,1);
            insert(minHeap,&minsz,a,0);
        }
        if(minsz>maxsz){
           av = minHeap[0];
        }else if(minsz<maxsz){
           av = maxHeap[0];
        }else{
            av = minHeap[0];
            av = (av+maxHeap[0])/2.0;
        }
        printf("%.2f ",av);
    }
    return 0;
}