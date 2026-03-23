#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int front = -1;
int back = -1;
int topIdx = -1;
int isEmptyS(int* stk){
    return topIdx==-1;
}
void push(int* stk,int x){
    stk[++topIdx]=x;
    return;
}
void pop(int* stk){
    if(isEmptyS(stk))return;
    topIdx--;
}
int top(int* stk){
    int val = stk[topIdx];
    return val;
}

int isEmptyQ(int* q){
    return (front == -1 && back == -1)||(front>back);
}
void enqueue(int* q,int x){
    if(front == -1||front>back){
        front = back = 0;
    }else{
        back++;
    }
    q[back] = x;
}
int peek(int* q){
    if(front == -1)return -1;
    int val = q[front];
    return val;
}
void dequeue(int* q){
    front++;
}
int main(){
    int n;
    scanf("%d",&n);
    int q[MAX];
    int s[n];
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        enqueue(q,x);
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<(n/2);j++){
            push(s,peek(q));
            dequeue(q);
        }
        while(topIdx>-1){
            enqueue(q,top(s));
            pop(s);
        }
    }
    for(int i=0;i<n/2;i++){
        push(s,peek(q));
        dequeue(q);
    }
    while(topIdx>-1){
        printf("%d %d ",peek(q),top(s));
        dequeue(q);
        pop(s);
    }
    printf("\n");
    return 0;
}