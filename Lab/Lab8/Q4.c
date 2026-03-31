//Nice
#include <stdio.h>
#include <stdlib.h>
typedef struct Pair{
    int s; //sum
    int u; //val
}Pair;
void swap(Pair* a,Pair* b){
    Pair t = *a;
    *a = *b;
    *b = t;
    return;
}
int cmp(Pair a,Pair b){
    return a.s <= b.s;
}
void heapifyUp(Pair* heap,int* sz,int idx){

    if(idx<=0)return;

    if(!cmp(heap[idx],heap[(idx-1)/2]))return; //greater than parent so min heap

    swap(&heap[idx],&heap[(idx-1)/2]);
    heapifyUp(heap,sz,(idx-1)/2);

    return;
}
void heapifyDown(Pair* heap,int* sz,int idx){

    if(2*idx+1>= *sz)return;

    int left = 2*idx+1;
    int right = 2*idx+2;

    int smallest = left;
    if(right<*sz && cmp(heap[right],heap[smallest])){
        smallest = right;
    }
    if(!cmp(heap[idx],heap[smallest])){

        swap(&heap[idx],&heap[smallest]);
        heapifyDown(heap,sz,smallest);

    }
    return;
}

void insert(Pair* heap,int* sz,int x,int y){

    Pair newPair = {x+y,x};
    heap[*sz] =  newPair;
    heapifyUp(heap,sz,*sz);
    *sz = *sz+1;

}
Pair pullRoot(Pair* heap,int* sz){
    Pair ans = heap[0];
    heap[0] = heap[*sz-1];
    *sz = (*sz)-1;
    heapifyDown(heap,sz,0);
    return ans;
}

int main(){
    int n1,n2;
    scanf("%d %d",&n1,&n2);
    int a1[n1];
    int a2[n2];
    for(int i=0;i<n1;i++){
        scanf("%d",&a1[i]);
    }
    for(int i=0;i<n2;i++){
        scanf("%d",&a2[i]);
    }
    int k;
    scanf("%d",&k);
    Pair heap[10000];
    int sz = 0;
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            insert(heap,&sz,a1[i],a2[j]);
        }
    }
    for(int i=0;i<k;i++){
        Pair p = pullRoot(heap,&sz);
        printf("%d %d\n",p.u,p.s-p.u);
    }
    return 0;
}