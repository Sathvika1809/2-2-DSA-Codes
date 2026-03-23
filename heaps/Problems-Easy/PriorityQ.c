#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct PriorityQueue
{
    int heap[MAX];
    int size;
};
void swap(int* a,int* b){
    int temp = *a;
    *a=*b;
    *b = temp;
}

void maxHeapify(struct PriorityQueue *pq, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < pq->size && pq->heap[left] > pq->heap[largest])
        largest = left;
    if(right < pq->size && pq->heap[right] > pq->heap[largest])
        largest = right;
    if(largest != i)
    {
        swap(&pq->heap[i], &pq->heap[largest]);
        maxHeapify(pq, largest);
    }
}
int extractMax(struct PriorityQueue *pq)
{
    if(pq->size <= 0)
    {
        printf("Underflow\n");
        return -1;
    }

    if(pq->size == 1)
    {
        pq->size--;
        return pq->heap[0];
    }

    int root = pq->heap[0];

    pq->heap[0] = pq->heap[pq->size-1];
    pq->size--;

    maxHeapify(pq, 0);

    return root;
}
int peek(struct PriorityQueue *pq)
{
    if(pq->size <= 0)
        return -1;

    return pq->heap[0];
}