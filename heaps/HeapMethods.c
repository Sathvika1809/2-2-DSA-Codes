#include <stdio.h>
#include <stdlib.h>
typedef struct Heap{
    int* a;
    int size;
    int capacity;
}Heap;
Heap* createHeap(int capacity){
    Heap* heap =(Heap*)malloc(sizeof(Heap));
    heap->size = 0;
    heap->capacity=capacity;
    heap->a=(int*)malloc(capacity*(sizeof(int)));
    return heap;
}
void swap(int* a,int* b){
    int t=*a;
    *a=*b;
    *b=t;
    return;
}
void heapify(Heap* heap,int i){
    int maxm=i;
    int left = 2*i+1;
    int right=2*i+2;
    while(left<heap->size&&heap->a[left]>heap->a[maxm])maxm=left;
    while(right<heap->size&&heap->a[right]>heap->a[maxm])maxm=right;
    if(maxm!=i){
        swap(&heap->a[i],&heap->a[maxm]);
        heapify(heap,maxm);
    }
    return;
}

void buildheap(Heap* heap){
    int n = (heap->size);
    for(int i=(n-1)/2;i>=0;i--){
        heapify(heap,i);
    }
}
void insertHeap(Heap* heap,int val){
    if(heap->size == heap->capacity)return;
    heap->size++;
    int i = heap->size-1;
    heap->a[i]=val;
    while(i!=0&&heap->a[(i-1)/2]<heap->a[i]){
        swap(&heap->a[(i-1)/2],&heap->a[i]);
        i=(i-1)/2;
    }
    return; 
}
int extractMax(Heap* heap){
    if(heap->size==0){
        return -1;
    }
    if(heap->size==1){
       heap->size--;
       return heap->a[0];
    }
    int root = heap->a[0];
    heap->a[0]=heap->a[heap->size-1];
    heap->size--;
    heapify(heap,0);
    return root;
}
void printHeap(Heap* heap){
    for(int i=0;i<heap->size;i++){
        printf("%d ",heap->a[i]);
    }
        printf("\n");
        return;
}
void deleteKey(Heap* heap,int idx){
    if(idx>=heap->size){
        printf("Invalid\n");
        return;
    }
    if(idx==heap->size-1){
        heap->size--;
        return;
    }
    heap->a[idx]=heap->a[heap->size-1];
    heap->size--;
    heapify(heap,idx);
}
void increaseKey(Heap* heap,int idx,int val){
    if(idx>=heap->size||heap->a[idx]>=val){
        printf("Invalid index\n or new Value is not greater\n");
        return;
    }
    heap->a[idx]=val;
    while(idx!=0&&heap->a[(idx-1)/2]<heap->a[idx]){
        swap(&heap->a[(idx-1)/2],&heap->a[idx]);
        idx=(idx-1)/2;
    }
}


int main(){
    int n;
    scanf("%d",&n);
    Heap* heap = createHeap(n);
    //insertHeap(heap,3);
   
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        insertHeap(heap,x);
    }
    // insertHeap(heap,3);
    // insertHeap(heap,3);
    // insertHeap(heap,3);
    printf("Max Heap Array:\n");
    printHeap(heap);
    printf("Extracted Max: %d\n",extractMax(heap));
    printf("Max Heap Array after extraction:\n");
    printHeap(heap);
    free(heap->a);
    free(heap);
    return 0;

    

    return 0;
}