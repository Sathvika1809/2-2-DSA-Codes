#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
int heap[MAX];
int sz = 0;
void swap(int*a ,int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
void heapifyUp(int idx){
    if(idx<=0)return;
    int parent = (idx-1)/2;
    //max Heap - parent>child
    if(heap[parent]<heap[idx]){
        swap(&heap[parent],&heap[idx]);
        heapifyUp(parent);
    }
    return;
}
void heapifyDown(int idx){
    if(2*idx+1>=sz)return;
    int left = 2*idx+1;
    int largest = left;
    if(2*idx+2<sz&&heap[2*idx+2]>heap[largest]){
        largest = 2*idx+2;
    }
    if(heap[largest]>heap[idx]){
        swap(&heap[largest],&heap[idx]);
        heapifyDown(largest);
    }
    return;
}
int pullRoot(){
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

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[26]={0};
    for(int i=0;i<n;i++){
        char ch;
        scanf(" %c",&ch);
        a[ch-'A']++;
    }
    for(int i=0;i<n;i++){
        if(a[i]){
            insert(a[i]);
        }
    }
    int ans = 0;
    while(sz>0){
        int curr = pullRoot();
        curr--;
        ans++;
        int temp[MAX];
        int x  = 0;
        for(int i=0;i<k;i++){
            if(curr==0&&sz==0){
                int ok = 1;
                for(int j=0;j<x;j++){
                    if(temp[j]!=0)ok = 0;
                }
                if(ok){
                    printf("%d\n",ans);
                    return 0;
                }
            }
            ans++;
            if(sz!=0){
                int cur = pullRoot();
                temp[x++] = cur-1;
            }
        }
        if(curr!=0){
            insert(curr);
        }
        for(int j=0;j<x;j++){
            if(temp[j]!=0){
                insert(temp[j]);
            }
        }

    }
    printf("%d\n",ans);
    return 0;
}