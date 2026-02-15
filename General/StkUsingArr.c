#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int topIdx = -1;
int isEmpty(int* stack){
    return topIdx == -1;
}
void push(int* stack,int val){
    stack[++topIdx] = val;
    return;
}
void pop(int* stack){
    if(!isEmpty(stack)) topIdx--;
    return;
}
int top(int* stack){
    if(isEmpty(stack)){
        printf("The stack is Empty\n");
        return -1;
    }
    return stack[topIdx];
}
int main(){
int stack[MAX];
push(stack,1);
push(stack,2);
push(stack,3);
push(stack,4);
push(stack,5);
printf("%d\n",top(stack));
printf("%d\n",isEmpty(stack));
pop(stack);
while(!isEmpty(stack)){
    printf("%d\n",top(stack));
    pop(stack);
}
return 0;
}