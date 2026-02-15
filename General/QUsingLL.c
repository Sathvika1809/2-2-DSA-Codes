#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;
typedef struct Queue{
    Node* front;
    Node* back;
    int size;
}Queue;
Node* createNode(int val);
Node* insertAtTail(Queue* q,int val);
void insert(Queue* q,int val);
Node* deleteFromHead(Queue* q);
Queue* initQ();
Queue* readQ();
void printQ(Queue* q);
void pop(Queue* q);
int front(Queue* q);
int size(Queue* q);
int isEmpty(Queue* q);
void clear(Queue* q);

int main(){
    Queue* q = readQ();
    printQ(q);
    pop(q);
    printQ(q);

    return 0;
}
int front(Queue* q){
    if(q->front == NULL){
        return -1;
    }
    return q->front->data;
}
int size(Queue* q){
    return q->size;
}
int isEmpty(Queue* q){
    return q->size==0;
}
void clear(Queue* q){
    while(q->size>0){
        pop(q);
    }
    return;
}
Node* createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
void pop(Queue* q){
    if(q->size==0){
        return;
    }
    q->front = deleteFromHead(q);
    q->size = (q->size)-1;
    return;
}
void printQ(Queue* q){
    Node* curr = q->front;
    while(curr!=NULL){
        printf("%d ",curr->data);
        curr = curr->next;
    }
    printf("\n");
}
void insert(Queue* q,int val){
   q->back = insertAtTail(q,val);
   q->size =(q->size)+1;
   return;
}
Node* insertAtTail(Queue* q,int val){
    Node* newNode = createNode(val);
    if(q->size>0){
        q->back->next = newNode;
        q->back = newNode;
    }else{
        q->front = newNode;
        q->back = newNode;
    }
    return newNode;
}
Node* deleteFromHead(Queue* q){
    if(q->front==NULL){
        return NULL;
    }
    if(q->front == q->back){
        Node* currHead = q->front;
        q->front = NULL;
        q->back = NULL;
        currHead->next = NULL;
        free(currHead);
        return NULL;
    }
    Node* currHead = q->front;
    Node* newHead = q->front->next;
    currHead->next = NULL;
    free(currHead);
    return newHead;
}
Queue* initQ(){
    Queue* q=(Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->back = NULL;
    q->size = 0;
    return q;
}
Queue* readQ(){
    Queue* q = initQ();
    int n;
    scanf("%d",&n);
    while(n--){
        int temp;
        scanf("%d",&temp);
        insert(q,temp);
    }
    return q;
}