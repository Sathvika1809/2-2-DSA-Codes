#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int top1 = -1;
int top2 = -1;
int peek(int* stk1,int* stk2){
    if(top1 == -1)return -1;
    return stk1[top1];
}
int dequeue(int* stk1,int* stk2){
    if(top1 == -1) return -1;
    int val = peek(stk1,stk2);
    top1--;
    return val;
}
void enqueue(int* stk1,int* stk2,int x){
    while(top1!=-1){
        stk2[++top2] = stk1[top1--];
    }
    stk1[++top1] = x;
    while(top2!=-1){
        stk1[++top1] = stk2[top2--];
    }
}


int main(){
    int T;
    scanf("%d",&T);
    int a[T],b[T];
    int stk1[MAX];
    int stk2[MAX];
    for(int i=0;i<T;i++){
       scanf("%d",&a[i]);
       if(a[i]==1){
        scanf("%d",&b[i]);
       }
    }
    for(int i=0;i<T;i++){
        if(a[i]==1){
            enqueue(stk1,stk2,b[i]);
        }else if(a[i]==2){
            printf("%d\n",dequeue(stk1,stk2));
        }else{
            printf("%d\n",peek(stk1,stk2));
        }
    }
    return 0;
}
