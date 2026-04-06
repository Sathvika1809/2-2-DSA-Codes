#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
typedef struct Pair{
    int d;
    int r;
}Pair;

int heap[MAX];
int sz = 0;
int k;
void swapPair(Pair* a,Pair* b){
    Pair c = *a;
    *a = *b;
    *b = c;
}
void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
    return;
}

int cmp(Pair a,Pair b){
    if(a.d>b.d) return 1;
    else if(a.d<b.d)return 0;
    return a.r>=b.r;
}
void sort(Pair* list,int n){
    for(int i=0;i<n;i++){
        int swapped = 0;
        for(int j=0;j<n-i-1;j++){
            if(cmp(list[i],list[j])){
                swapPair(&list[i],&list[j]);
                swapped = 1;
            }
        }
        if(!swapped){
            break;
        }
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
    int ans = heap[0];
    heap[0] = heap[sz-1];
    sz--;
    heapifyDown(0);
    return ans;
}
void insert(int val){
    heap[sz++] = val;
    heapifyUp(sz-1);
}

int main(){
    int n;
    scanf("%d",&n);
    Pair list[n];
    for(int i=0;i<n;i++){
        scanf("%d %d",&list[i].d,&list[i].r);
    }
    sort(list,n);
    for(int i=0;i<n;i++){
        if(sz<list[i].d){
            insert(list[i].r);
        }else if(heap[0]<list[i].r){
            removeMin();
            insert(list[i].r);
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans+=heap[i];
    }

    printf("%d\n",ans);

    return 0;

}