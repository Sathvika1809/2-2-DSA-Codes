/*
Type 0 - min Heap
Type1 - max Heap
*/


#include <stdio.h>
#include <stdlib.h>
#define MAX 10000


void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
    return;
}
void heapifyDown(int* heap,int* sz,int idx,int type){
  if(type==0){
    if(idx>=*sz-1) return;
    if(2*idx+1>=*sz)return;
    int left = 2*idx+1;
    int right = 2*idx+2;
    int smallest = left;
    if(right<*sz&&heap[right]<heap[left]){
        smallest = right;
    }
    if(heap[idx]>heap[smallest]){
        swap(&heap[idx],&heap[smallest]);
        heapifyDown(heap,sz,smallest,type);
    }
}else{
    if(idx >= *sz-1)return;
    if(2*idx+1 >= *sz)return;
    int maxm = 2*idx+1;
    if(2*idx+2<*sz && heap[2*idx+2]>heap[maxm]){
        maxm = 2*idx+2;
    }
    if(heap[idx] <= heap[maxm]) return;
    swap(&heap[maxm],&heap[idx]);
    heapifyDown(heap,sz,maxm,type);
}   
}

void heapifyUp(int* heap, int* sz, int idx, int type){
    if(type == 0){
        if(idx == 0) return;

        if(heap[idx] >= heap[(idx-1)/2]) return;
        swap(&heap[idx], &heap[(idx-1)/2]);
        heapifyUp(heap, sz, (idx-1)/2, type);

    }else if(type==1){
        if(idx == 0) return;

        if(heap[idx] <= heap[(idx-1)/2]) return;
        swap(&heap[idx], &heap[(idx-1)/2]);
        heapifyUp(heap, sz, (idx-1)/2, type);

    }
}
void insert(int* heap,int* sz,int val,int type){
    heap[*sz] = val;
    heapifyUp(heap,sz,*sz,type);
    *sz = *sz+1;
}

int pullRoot(int* heap,int* sz,int type){
    int ans = heap[0];
    heap[0] = heap[*sz-1];
    *sz = *sz-1;
    heapifyDown(heap,sz,0,type);
    return ans;
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int minHeap[10000];
    int minsz = 0;
    int maxHeap[10000];
    int maxsz = 0;
    insert(minHeap,&minsz,a[0],0);
    float av = a[0];
    printf("%.1f ",av);
    for(int i=1;i<n;i++){
        if(a[i]>minHeap[0]){
            insert(minHeap,&minsz,a[i],0);
        }else{
            insert(maxHeap,&maxsz,a[i],1);
        }

        if(minsz > 1+maxsz){
            int x = pullRoot(minHeap,&minsz,0);
            insert(maxHeap,&maxsz,x,1);
        }else if(maxsz > 1+minsz){
            int x = pullRoot(maxHeap,&maxsz,1);
            insert(minHeap,&minsz,x,0);
        }

        if(maxsz > minsz){
            av = maxHeap[0];
        }else if(minsz > maxsz){
            av = minHeap[0];
        }else{
            av = maxHeap[0];
            av = (av+minHeap[0])/2;
        }
        printf("%.1f ",av);
    }
    printf("\n");
    return 0;
}