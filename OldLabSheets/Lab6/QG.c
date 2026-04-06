#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

int topIdx = -1;
int isEmpty(int* stack){
    return topIdx==-1;
}
void push(int* stack,int val){
    stack[++topIdx]=val;
}
void pop(int* stack){
    if(isEmpty(stack)){
        return;
    }
    topIdx--;
}
int top(int* stack){
    if(isEmpty(stack)){
        return -1;
    }else{
        return stack[topIdx];
    }
}

int main(){
    int stack[MAX];
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int ans[n];
    for(int i=0;i<n;i++){
        while(!isEmpty(stack)&&a[top(stack)]<=a[i]){
            pop(stack);
        }
        if(isEmpty(stack)){
            ans[i] = 1;
           
        }else{
            ans[i] = i-top(stack);
        }
         push(stack,i);
    }
    for(int i=0;i<n;i++){
        printf("%d ",ans[i]);
    }

    return 0;
}