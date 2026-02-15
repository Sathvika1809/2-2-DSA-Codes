#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000
int topIdx = -1;
int isEmpty(int* st){
    return topIdx==-1;
}
int isFull(int* st){
    return topIdx>=MAX_SIZE-1;
}
void push(int* st,int val){
    if(isFull(st)){
        return;
    }
    st[++topIdx]=val;
    return;
}
void pop(int* st){
    if(isEmpty(st)){
        return;
    }
    
    topIdx--;
    return;
}
int top(int* st){
    if(isEmpty(st)){
        return -1;
    }
    return st[topIdx];
}
int main(){
    int stk[MAX_SIZE];
    int n;
    scanf("%d",&n);
    int a[n];
    int ans[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        while(!isEmpty(stk)&& a[top(stk)]<=a[i]) pop(stk);
        if(isEmpty(stk)){
            ans[i]=i+1;
        }else{
            ans[i]=i-top(stk);
        }
        push(stk,i);
    }
    for(int i=0;i<n;i++) printf("%d ",ans[i]);
    printf("\n");
    return 0;
}
