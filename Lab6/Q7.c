#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000
int topIdx = -1;
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
    topIdx--;
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
    char str[n];
    scanf("%s",str);
    while(s[i]!='\0'){
       if(s[i]>='0'&&s[i]<='9'){
        
       }
    }

    return 0;
}