#include <stdio.h>
#include <stdlib.h>
typedef struct Node_t{
    int data;
    struct Node_t* next;
}Node;

typedef struct Stack_t{
    Node* top;
    int sz;
}Stack;

// These are all implemented Functions

Node* createNode(int val);
Node* insertAtHead(Stack* stk,int val);
Node* deleteFromHead(Stack* stk);
Stack* initStack();
Stack* readStack();
void printStack(Stack* stk);
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
    printf("Size: %d\n",size(stk));
    printStack(stk);
    push(stk,100);
    printf("Size: %d\n",size(stk));
    printStack(stk);
    clear(stk);
    printf("Size: %d\n",size(stk));
    printStack(stk);
  
    return 0;
}
Stack* initStack(){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->sz = 0;
    return stack;
}
int top(Stack* stk){
    if(isEmpty(stk)){
        return -1;
    }else{
        return stk->top->data;
    }
}
int size(Stack* stk){
    return stk->sz;
}
Stack* readStack(){
    Stack* stk = initStack();
    int n;
    scanf("%d",&n);
    while(n--){
        int x;
        scanf("%d",&x);
        push(stk,x);
    }
    return stk;
}
Node* insertAtHead(Stack* stk,int val){
    Node* newHead = createNode(val);
    newHead->next = stk->top; // This is the important step
    //Making top thing at last adding everyhting first
    return newHead;
}
Node* deleteFromHead(Stack* stk){
    if(stk->top == NULL){
        return NULL;
    }
    Node* currHead = stk->top;
    Node* newHead = stk->top->next;
    currHead->next = NULL;
    free(currHead);
    return newHead;
}
void push(Stack* stk,int val){
    stk->top = insertAtHead(stk,val);
    stk->sz = (stk->sz)+1;
    return;

}
void clear(Stack* stk){
    while(size(stk)>0){
        pop(stk);
    }
    return;
}
int isEmpty(Stack* stk){
    return (stk->sz == 0);
}
void printStack(Stack* stk){
    Node* temp = stk->top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}