#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct Node_t{
    int data;
    struct Node_t* next;
}Node;
typedef struct Stack_t{
    Node* top;
    int size;
}Stack;
Node* createNode(int val);
Node* insertAtHead(Stack* stk,int val);
Node* deleteFromHead(Stack* stk);
Stack* initStack();
Stack* readStack();
void printStack(Stack* st);
void push(Stack* stk,int val);
void pop(Stack* stk);
int top(Stack* stk);
int size(Stack* stk);
int isEmpty(Stack* stk);
void clear(Stack* stk);
int main(){
    Stack* stk = readStack();
    printf("Size: %d\n",size(stk));
    printStack(stk);
    pop(stk);
    pop(stk);
    printf("Size: %d\n", size(stk));
    printStack(stk);
    push(stk, 100);
    printf("Size: %d\n", size(stk));
    printStack(stk);
    clear(stk);
    printf("Size: %d\n", size(stk));
    printStack(stk);


    return 0;
}
int isEmpty(Stack* stk){
    
    return (stk->size == 0);
}
void clear(Stack* stk){
    while(size(stk)>0){
        pop(stk);
    }
    return;
}
Node* createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
Node* insertAtHead(Stack* stk,int val){
    Node* newHead = createNode(val);
    newHead->next = stk->top;
    return newHead;
    
}
Node* deleteFromHead(Stack* stk){
    if(stk->top==NULL){
        return NULL;
    }
    Node* deleteNode = stk->top;
    Node* currNode = stk->top->next;
    deleteNode->next = NULL;
    free(deleteNode);
    return currNode;
}
Stack* initStack(){
    Stack* st = (Stack*)malloc(sizeof(Stack));
    st->top = NULL;
    st->size = 0;
    return st;
}
Stack* readStack(){
    Stack* st = initStack();
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        push(st,temp);
    }
    return st;
}
void printStack(Stack* st){
    Node* curr = st->top;
    while(curr!=NULL){
        printf("%d ",curr->data);
        curr = curr->next;
    }
    printf("\n");
    return;
}
void push(Stack* stk,int val){
    stk->top = insertAtHead(stk,val);
    stk->size = (stk->size)+1;
    return;
}
void pop(Stack* stk){
    if(isEmpty(stk)){
        return;
    }
    stk->top = deleteFromHead(stk);
    stk->size = (stk->size)-1;
    return;
}
int top(Stack* stk){
    if(!isEmpty(stk)){
        return -1;
    }
    return stk->top->data;
}
int size(Stack* stk){
    return stk->size;
}
