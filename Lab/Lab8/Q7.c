#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
int heap[MAX];
int sz = 0;

void swap(int* a,int* b){
    int t =*a;
    *a =*b;
    *b = t;
}
void heapifyDown(int idx){
    if(idx>=sz-1)return;
    if(2*idx+1>=sz)return;
    int left = 2*idx+1;
    int largest = left;
    if(2*idx+2<sz&&heap[2*idx+2]>heap[largest]){
        largest = 2*idx+2;
    }
    if(heap[idx]<heap[largest]){
        swap(&heap[idx],&heap[largest]);
        heapifyDown(largest);
    }

}
void heapifyUp(int idx){
    if(idx<=0)return;
    int parent = (idx-1)/2;
    if(heap[parent]<heap[idx]){
        swap(&heap[parent],&heap[idx]);
        heapifyUp(parent);
    }
    return;
}
void insert(int val){
    heap[sz++]=val;
    heapifyUp(sz-1);
}
int removeMin(){
   int val = heap[0];
   heap[0] = heap[sz-1];
   sz--;
   heapifyDown(0);
   return val;
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[26]={0};
    for(int i=0;i<n;i++){
        char c;
        scanf(" %c",&c);
        a[c-'A']++;
    }
    for(int i=0;i<26;i++){
        if(a[i]){
            insert(a[i]);
        }
    }
    int ans = 0;
    while(sz>0){
        ans++;
        int curr = removeMin();
        curr--;
        int temp[MAX];
        int x = 0;
        for(int i=0;i<k;i++){
            if(curr==0 && sz==0){
                int ok = 1;
                for(int j=0;j<x;j++){
                    if(temp[j]!=0)ok=0;
                }
                if(ok){
                    printf("%d\n",ans);
                    return 0;
                }
            }
            ans++;
            if(sz!=0){
                int cur = removeMin();
                temp[x++] = cur-1;
            }
        }
        if(curr!=0)insert(curr);
        for(int i=0;i<x;i++){
            if(temp[i]!=0){
                insert(temp[i]);
            }
        }
        
    }

    printf("%d\n",ans);
    return 0;
}