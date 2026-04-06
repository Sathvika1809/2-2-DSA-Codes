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
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    int stack[MAX];
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int prev[n];
    int next[n];
    for(int i=0;i<n;i++){
        while(!isEmpty(stack)&&a[top(stack)]>=a[i]){
            pop(stack);
        }
        if(isEmpty(stack)){
            prev[i] = -1;
           
        }else{
            prev[i] = top(stack); //store the indices here
        }
        push(stack,i);
    }
    topIdx = -1;
    for(int i=n-1;i>=0;i--){
        while(!isEmpty(stack)&&a[top(stack)]>=a[i]){
            pop(stack);
        }
        if(isEmpty(stack)){
            next[i]=n;
        }else{
            next[i] = top(stack);
        }
        push(stack,i);
    }
    int ans  = 0;
    for(int i=0;i<n;i++){
        int area = (next[i]-prev[i]-1)*a[i];
        ans = max(area,ans);
    }
    printf("%d\n",ans);
    return 0;
}