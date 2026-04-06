#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

typedef struct Node_t{
    int val;
    int r;
    int c;
}Node;
Node heap[MAX];
int sz = 0;
void swap(Node*a ,Node* b){
    Node t =*a;
    *a=*b;
    *b = t;
}
int cmp(Node a,Node b){
    return a.val<=b.val;
}
void heapifyUp(int idx){
    if(idx<=0)return;
    int parent = (idx-1)/2;
    if(cmp(heap[idx],heap[parent])){
        swap(&heap[parent],&heap[idx]);
        heapifyUp(parent);
    }
    return;
}
void heapifyDown(int idx){
    if(2*idx+1>=sz)return;
    int left = 2*idx+1;
    int smallest = left;
    if(2*idx+2<sz&&cmp(heap[2*idx+2],heap[smallest])){
        smallest = 2*idx+2;
    }
    if(cmp(heap[smallest],heap[idx])){
        swap(&heap[smallest],&heap[idx]);
        heapifyDown(smallest);
    }
    return;
}
void insert(int x,int i,int j){
    Node newNode = {x,i,j};
    heap[sz++] = newNode;
    heapifyUp(sz-1);
}
Node pullRoot(){
  Node newNode = heap[0];
  heap[0] = heap[sz-1];
  sz--;
  heapifyDown(0);
  return newNode;
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int k;
    scanf("%d",&k);
    for(int i=0;i<n;i++){
        insert(a[i][0],i,0);
    }
    for(int i=0;i<k-1;i++){
        Node cur = pullRoot();
        int x = cur.r;
        int y = cur.c;
        insert(a[x][y+1],x,y+1);
    }
    printf("%d\n",heap[0].val);
    return 0;
}