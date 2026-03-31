#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
int front = -1;
int back = -1;
int topIdx = -1;

void push(int* stk,int x){
    stk[++topIdx]=x;
}
void pop(int* stk){
    if(topIdx==-1){
        return;
    }
    topIdx--;
}
int top(int* stk){
    return stk[topIdx];
}
void enqueue(int* q,int x){
    if(front == -1){
        front = back =0;
    }else{
        back++;
    }
    q[back] = x;
}
int peek(int* q){
    return q[front];
}
void dequeue(){
    front++;
}

int main(){
    int n;
    scanf("%d",&n);
    int q[MAX];
    int stk[MAX];
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        enqueue(q,x);
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<(n/2);j++){
            push(stk,peek(q));
            dequeue(q);
        }
        while(topIdx>-1){
            enqueue(q,top(stk));
            pop(stk);
        }
    }
    for(int i=0;i<(n/2);i++){
        push(stk,peek(q));
        dequeue(q);
    }
    while(topIdx>-1){
        printf("%d %d ",peek(q),top(stk));
        dequeue(q);
        pop(stk);
    }

    return 0;
}