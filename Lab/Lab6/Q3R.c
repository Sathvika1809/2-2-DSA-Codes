#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int topIdx=-1;
int isEmpty(int* st){
    return topIdx==-1;
}
void push(int* st,int val){
    st[++topIdx]=val;
    return;
}
void pop(int* st){
    
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
    int n;
    scanf("%d",&n);
    int a[n];
    int st[MAX];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    
   int ans  = 0;
    int prev[n];
    int next[n];
    for(int i=0;i<n;i++){
        while(!isEmpty(st)&&a[st[topIdx]]>=a[i]){
            pop(st);
        }
        if(isEmpty(st)){
            prev[i] = -1;
        }else{
            prev[i] = top(st);
        }
        push(st,i);
    }
    topIdx=-1;
    for(int i=n-1;i>=0;i++){
        while(!isEmpty(st)&&a[st[topIdx]]>=a[i]){
            pop(st);
        }
        if(isEmpty(st)){
            next[i] = n;
        }else{
            next[i] = top(st);
        }
        push(st,i);
    }
     for(int i=0;i<n;i++){
        int area = (next[i]-prev[i]-1)*a[i];
        area = max(area,a[i]);
        ans = max(ans,area);
    }
    printf("%d\n",ans);
    return 0;
}