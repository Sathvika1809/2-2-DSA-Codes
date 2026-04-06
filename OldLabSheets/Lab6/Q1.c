#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
int topIdx = -1;
typedef struct Pair{
    int ff;
    int ss;
}Pair;
int isEmpty(Pair* stk[]){
    return topIdx==-1;
}
Pair* createNode(int x){
    Pair* newNode = (Pair*)malloc(sizeof(Pair));
    newNode->ff = x;
    newNode->ss = 0;
    return newNode;
}
Pair* top(Pair* stk[]){
    return stk[topIdx];
}
void pop(Pair* stk[]){
    if(isEmpty(stk)){
        return;
    }
    topIdx--;
}
int min(int a,int b){
    return a<b?a:b;
}
void push(Pair* stk[],int val){
   Pair* newNode = createNode(val);
   if(isEmpty(stk)){
      newNode->ss = newNode->ff;
   }else{
        newNode->ss = min(newNode->ff,top(stk)->ss);
   }
   stk[++topIdx]= newNode;
   return;

}
int getMin(Pair* stk[]){
    if(isEmpty(stk)){
        return -1;
    }
    return stk[topIdx]->ss;
}
void MinStack(){
    Pair* stack[MAX];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        push(stack,x);
    }
    int m;
    scanf("%d",&m);
    Pair inp[m];
    for(int i=0;i<m;i++){
        scanf("%d",&inp[i].ff);
        if(inp[i].ff==1){
            scanf("%d",&inp[i].ss);
        }
    }
    for(int i=0;i<m;i++){
        int op = inp[i].ff;
        if(op==1){
            push(stack,inp[i].ss);
        }else if(op == 2){
            if(isEmpty(stack)){
                printf("Stack Empty\n");
            }else{
                pop(stack);
            }
        }else if(op == 3){
            if(isEmpty(stack)){
                printf("Stack is Empty\n");
            }else{
                printf("%d\n",top(stack)->ff);
            }
        }else{
            if(isEmpty(stack)){
                printf("Stack is Empty\n");
            }else{
                printf("%d\n",getMin(stack));
            }
        }
    }
    return;

}
int main(){
    MinStack();
    return 0;
}