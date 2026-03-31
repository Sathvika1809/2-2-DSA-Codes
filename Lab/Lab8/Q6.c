#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
int heap[MAX];
int sz = 0;
void swap(int* a,int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
void heapifyDown(int idx){
    if(idx >= sz-1) return;
    if(2*idx+1>=sz) return;
    int left = 2*idx+1;
    int smallest = left;
    if(2*idx+2<sz && heap[2*idx+2]<heap[left]){
        smallest = 2*idx+2;
    }
    if(heap[idx]>heap[smallest]){
        swap(&heap[idx],&heap[smallest]);
        heapifyDown(smallest);
    }
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
void insert(int x){
    heap[sz++]=x;
    heapifyUp(sz-1);
    return;
}
int removeMin(){
    int val = heap[0];
    heap[0] = heap[sz-1];
    sz--;
    heapifyDown(0);
    return val;
}

int main(){
    int n;
    scanf("%d",&n);
    int visited[10000] = {0};
    insert(2);
    insert(5);
    insert(7);
    visited[2]=visited[5]=visited[7]=1;
    int val;

    for(int i=0;i<n;i++){
        val = removeMin();
        int a = val*2;
        int b = val*5;
        int c = val*7;
        if(a<=10000 && !visited[a]){
            insert(a);
            visited[a] = 1;
        }
        if(b<=10000&&!visited[b]){
            insert(b);
            visited[b] = 1;
        }
        if(c<=10000&&!visited[c]){
            insert(c);
            visited[c] = 1;
        }   
     }
     printf("%d\n",val);
    
    return 0;
}