#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int top = -1;
typedef struct Pair{
    int ff;
    int ss;
}Pair;
Pair* createPair(int x){
    Pair* newPair = malloc(sizeof(Pair));
    newPair->ff = x;
    newPair->ss = 0;
    return newPair;
}
int min(int a ,int b){
    return a<b?a:b;
}
Pair* peek(Pair* st[]){
   
    return st[top];
}
int isEmpty(Pair* st[]){
    return top==-1;
}
void pop(Pair* st[]){
    if(isEmpty(st)){
        return;
    }
    top--;
}
void push(Pair* st[],int x){
    Pair* newPair = createPair(x);
    if(isEmpty(st)){
        newPair->ss = newPair->ff;
    }else{
        newPair->ss = min(newPair->ff,peek(st)->ss);
    }
    st[++top] = newPair;
    return;
}


int main(){
    int n;
    scanf("%d",&n);
    Pair* stk[MAX];
    Pair inp[n];
    for(int i=0;i<n;i++){
        scanf("%d",&inp[i].ff);
        if(inp[i].ff == 1){
            scanf("%d",&inp[i].ss);
        }
    }
    for(int i=0;i<n;i++){
        int op = inp[i].ff;
        if(op == 1){
            push(stk,inp[i].ss);
        }else if(op == 2){
            if(isEmpty(stk)){
                printf("Stack Empty\n");
                continue;
            }
            printf("Popped:%d\n",peek(stk)->ff);
            pop(stk);
        }else if(op == 3){
            if(isEmpty(stk)){
                printf("Stack is Empty\n");
                continue;
            }
            printf("Minimum: %d\n",peek(stk)->ss);
        }
        else if(op == 4){
            if(isEmpty(stk)){
                printf("Stack Empty\n");
                continue;
            }
            printf("Top: %d\n",peek(stk)->ff);
        }
    }
    return 0;
}
