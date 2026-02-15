#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000
int topIdx = -1;
int isEmpty(int* st){
    return topIdx==-1;
}
int max(int a,int b){
    return a>b?a:b;
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
    int stack[1000];
    char s[1000];
    scanf("%s",s);
    int i=0;
    int len = 0;
    push(stack, -1);
    while(s[i]!='\0'){
        if(s[i]=='('){
            push(stack,i);
        }else{
            pop(stack);
            if(isEmpty(stack)){
                push(stack,i);
            }
             else{
                len = max(len,i-top(stack));
            }
        }
        i++;
    }
    printf("%d\n",len);
    


    return 0;
}