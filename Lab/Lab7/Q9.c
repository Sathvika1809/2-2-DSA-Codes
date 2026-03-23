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
    int n,k;
    scanf("%d %d",&n,&k);
    k = k%n;
    int q[1000];
    int s[1000];
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        enqueue(q,x);
    }
    for(int i=0;i<k;i++){
        if(!isEmptyQ(q)){
        push(s,peek(q));
        }
        dequeue(q);
    }
    while(topIdx>-1){
        enqueue(q,top(s));
        pop(s);
    }
    for(int i=0;i<n-k;i++){
        int val = peek(q);
        push(s,val);
        dequeue(q);
        enqueue(q,top(s));
        pop(s);
    }
    
    while(!isEmptyQ(q)){
       printf("%d ",peek(q));
       dequeue(q);
    }
    return 0;
}