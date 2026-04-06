#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
int topIdx = -1;
int isEmpty(char* stack){
    return topIdx==-1;
}
void push(char* stack,char val){
    stack[++topIdx]=val;
}
void pop(char* stack){
    if(isEmpty(stack)){
        return;
    }
    topIdx--;
}
char top(char* stack){
    if(isEmpty(stack)){
        return -1;
    }else{
        return stack[topIdx];
    }
}
int main(){
    char str[MAX];
    char stack[MAX];
    scanf("%s",str);
    int i=0;
    int op = 0;
    while(str[i]!='\0'){
        if(str[i]=='('){
            push(stack,i);
        }else if(str[i]==')'){
            if(!isEmpty(stack)){
                pop(stack);
            }else{
                push(stack,str[i]);
            }
        }
        i++;
    }
    if(isEmpty(stack)){
        printf("0\n");
        return 0;
    }
    while(!isEmpty(stack)){
        op++;
        pop(stack);
    }
    printf("%d\n",op);


    return 0;
}