#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

typedef struct Node_t{
    int val;
    int i;
    int j;
}Node;

void swap(Node* a,Node* b){
    Node t = *a;
    *a = *b;
    *b =t;
    return;
}
int cmp(Node a,Node b){
    return a.val<=b.val;
}
void heapifyUp(Node* heap,int* sz,int idx){
    if(idx<=0)return;
    int parent = (idx-1)/2;
    if(cmp(heap[idx],heap[parent])){
        swap(&heap[parent],&heap[idx]);
        heapifyUp(heap,sz,parent);
    }
    return;
}
void heapifyDown(Node* heap,int* sz,int idx){
    if(2*idx+1>=*sz)return;
    int left = 2*idx+1;
    int smallest = left;
    if(2*idx+2<*sz&&cmp(heap[2*idx+2],heap[smallest])){
        smallest = 2*idx+2;
    }
    if(cmp(heap[smallest],heap[idx])){
        swap(&heap[idx],&heap[smallest]);
        heapifyDown(heap,sz,smallest);
    }
    return;
}
void insert(Node* heap,int* sz,int val,int x,int y){
    Node newNode = {val,x,y};
    heap[(*sz)++]= newNode;
    heapifyUp(heap,sz,*sz-1);
}
int max(int a,int b){
    return a>b?a:b;
}
Node pullRoot(Node* heap,int* sz){
    Node newNode = heap[0];
    heap[0] = heap[*sz-1];
    (*sz)--;
    heapifyDown(heap,sz,0);
    return newNode;
}
int main(){
    int k;
    scanf("%d",&k);
    int N[k];
    int a[k][10000];
    for(int i=0;i<k;i++){
        scanf("%d",&N[i]);
        for(int j=0;j<N[i];j++){
            scanf("%d",&a[i][j]);
        }
    }
    Node heap[10000];
    int sz = 0;
    int curr_max = -10000;
    for(int i=0;i<k;i++){
        insert(heap,&sz,a[i][0],i,0);
        curr_max = max(curr_max,a[i][0]);
    }
    int l = heap[0].val, r = curr_max;
    int ans = curr_max - heap[0].val; //max Range possible
    while(1){
        Node cur = pullRoot(heap,&sz);
        int ni = cur.i;
        int nj = cur.j;
        nj++;
        if(nj >= N[ni])break;
        insert(heap,&sz,a[ni][nj],ni,nj);
        curr_max = max(curr_max,a[ni][nj]);
        int curRange = curr_max - heap[0].val;
        if(curRange < ans || (curRange == ans && heap[0].val < l)){
            ans = curRange;
            l = heap[0].val;
            r = curr_max;
        }
    }
    printf("%d %d\n", l,r);
    return 0;
}