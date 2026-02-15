#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000
int topIdx=-1;
int isEmpty(int* st){
    return topIdx==-1;
}
void push(int* st,int val){
    st[++topIdx]=val;
    return;
}
void pop(int* st){
    if(isEmpty(st)){
        return;
    }
    int topp = st[topIdx];
    topIdx--;
    return;
}
int top(int* st){
    if(isEmpty(st)){
        return -1;
    }
    return st[topIdx];
}
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    int stk[MAX_SIZE];
    int n;
    scanf("%d",&n);
    int h[n];
    int l[n],r[n];
    
    int ans=0;
    for(int i=0;i<n;i++){
        scanf("%d",&h[i]);
    }
    for(int i=0;i<n;i++){
        while(!isEmpty(stk)&&h[top(stk)]>=h[i]){
            pop(stk);
        }
        if(isEmpty(stk)) l[i]=-1;
        else l[i]=top(stk);
        push(stk,i);
    }
    topIdx = -1;
    for(int i=n-1;i>=0;i--){
        while(!isEmpty(stk)&&h[top(stk)]>=h[i])pop(stk);
        if(isEmpty(stk)) r[i]=n;
        else r[i]=top(stk);
        push(stk,i);
    }
    for(int i=0;i<n;i++){
        int area = (r[i]-l[i]-1)*(h[i]);
        area = max(area,h[i]);
        ans = max(ans,area);
    }
    printf("%d\n",ans);
    



    return 0;
}

