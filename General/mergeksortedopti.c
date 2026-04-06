#include <stdio.h>
#include <stdlib.h>
struct ListNode* heap[10000];
int sz = 0;
void swap(struct ListNode** a,struct ListNode** b){
    struct ListNode* temp = *a;
    *a = *b;
    *b = temp;
}
void heapifyUp(struct ListNode** heap,int idx){
    if(idx<=0)return;

    int parent = (idx-1)/2;
    if(heap[parent]->val <= heap[idx]->val){
        break;
    }
    swap(&heap[parent],&heap[idx]);
    idx = parent;
}
void heapifyDown(struct ListNode** heap,int idx){
    if(2*idx+1>=sz)return;
    int left = 2*idx+1;
    int smallest = left;
    if(2*idx+2<sz&&heap[2*idx+2]->val<heap[left]){
        smallest = 2*idx+2;
    }
    if(idx!=smallest){
        swap(&heap[idx],&heap[smallest]);
        heapifyDown(heap,smallest);
    }
    return;
}

void push(struct ListNode** heap,int* sz,struct ListNode* node){
    heap[*sz] = node;
    heapifyUp(heap,*sz);
    *sz = *sz+1;
}
struct ListNode* popMin(struct ListNode** heap,int* sz){
    if(*sz==0) return NULL;
    struct ListNode* minNode = heap[0];
    heap[0] = heap[*sz-1];
    *sz = *sz-1;
    heapifyDown(heap,0);
    return minNode;
}
struct ListNode* mergeKLists(struct ListNode** lists,int* listsSize){
    if(listsSize == 0) return NULL;
    struct ListNode* heap[10001];
    int heapsize = 0;
    for(int i=0;i<listsSize;i++){
        if(lists[i]!=NULL){
            push(heap,&heapSize,lists[i]);
        }
    }
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    when(heapsize>0){
        struct ListNode* node = popMin(heap,&heapSize);

        tail->next = node;
        tail = tail->next;

        if(node->next!=NULL){
            push(heap,&heapSize,node->next);
        }
    }

    tail->next = NULL;
    return dummy.next;
}
int main(){








    return 0;
}