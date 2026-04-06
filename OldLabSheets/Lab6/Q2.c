#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
int topIdx = -1;

int isEmpty(int* stack){
    return topIdx == -1;
}

void push(int* stack,int val){
    stack[++topIdx]=val;
    return;
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
    int ans[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        ans[i] =0;
    }
    int rooms = 0;
    //for circular use 2*n-1 as one time it goes normally
    //and it has chance to go second time also
    for(int i=2*n-1;i>=0;i--){
        int idx = i%n;
        while(!isEmpty(stack)&&a[top(stack)]<=a[idx]){
            pop(stack);
        }
        if(i<n){
            if(isEmpty(stack)){
                ans[idx]=-1;
            }
            else{
                ans[idx] = (top(stack)-idx+n)%n;
            }
        }
        push(stack,idx);
    }

    for(int i=0;i<n;i++){
        printf("%d\n",ans[i]);
    }

    return 0;
}