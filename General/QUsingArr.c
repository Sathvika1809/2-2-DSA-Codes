#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
typedef struct Queue{
    int arr[MAX];
    int front;
    int rear;
}Queue;
Queue initQ(){
    Queue q;
    q.front =-1;
    q.rear=-1;
    return q;
}
void insert(Queue* q,int val){
    if(q->front ==-1){
        q->front = 0;
    }
    q->arr[++q->rear]=val;
}
Queue readQ(){
    Queue q = initQ();
    int n;
    scanf("%d",&n);
    int val;
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        insert(&q,val);
    }
    return q;
}
int isEmpty(Queue* q){
    return (q->front==-1 ||q->front>q->rear);
}

int delete(Queue* q){
    if(isEmpty(q)){
        return -1;
    }
    int val =q->arr[q->front];
    q->front++;
    return val;
}
int peek(Queue* q){
    if(isEmpty(q)){
        return -1;
    }
    return q->arr[q->front];
}
void display(Queue* q){
    if(isEmpty(q)){
        return;
    }
    for(int i=q->front;i<=q->rear;i++){
        printf("%d ",q->arr[i]);
    }
    printf("\n");
}
int main(){
    Queue q = readQ();
    display(&q);


    return 0;
}