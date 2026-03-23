#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
int topIdx=-1;
int isEmpty(int* st){
    return topIdx==-1;
}
void push(int* st,int val){
    st[++topIdx]=val;
}
void pop(int* st){
    topIdx--;
}
int top(int* st){
    if(isEmpty(st))return -1;
    return st[topIdx];
}
int main(){
    int n;
    scanf("%d",&n);
    int st[MAX];
    int a[n];
    int ans[n];
    
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=n-1;i>=0;i--){
        while(!isEmpty(st)&&a[top(st)]<=a[i]){
            pop(st);
        }
        if(isEmpty(st)){
            ans[i] = 0;
        }else{
            ans[i] = top(st)-i;
        }
        push(st,i);
    }
    for(int i=0;i<n;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}