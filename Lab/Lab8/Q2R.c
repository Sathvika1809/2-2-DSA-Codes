#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
int heap[MAX];
int sz=0;
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
int removeMin(){
    int val = heap[0];
    heap[0] = heap[sz-1];
    sz--;
    heapifyDown(0);
    return val;
}
void insert(int val){
    heap[sz++] = val;
    heapifyUp(sz-1);
}
int findCost(){
    int totCost = 0;
    while(sz>1){
    int a = removeMin();
    int b = removeMin();
    int val = a+b;
    insert(val);
    totCost+=val;
    }
    return totCost;
}
int main(){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int x;
        scanf("%d",&x);
        insert(x);
    }
    printf("%d\n",findCost());
    return 0;
}