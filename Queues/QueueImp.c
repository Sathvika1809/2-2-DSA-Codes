#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 1000
//enqueue - back++ and Dequeue front++
int front = -1;
int back = -1;
int isEmpty(int* q){
    return (front==-1&&back==-1)||(front>back);
}
int isFull(int* q){
    return back >=MAX-1;
}
void enqueue(int* q,int val){
    if(isFull(q)){
        printf("The Queue is Full Cant add\n");
        return;
    }
    if(front == -1){
        q[++front]=q[++back]=val;
    }else{
        q[++back]=val;
    }
    return;
}
int peek(int* q){
    if(front == -1){
        return -1;
    }
    int temp = q[front];
    return temp;
}
void display(int* q){
    if(front == -1){
        printf("Queue is Empty\n");
        return;
    }
    for(int i = front;i<=back;i++){
        printf("%d ",q[i]);
    }
    printf("\n");
}
void dequeue(int* q){
    if(front == -1||front>back){
        return;
    }
    printf("Deleted: %d\n",q[front]);
    front++;
    if(front>back){
        front=-1;
        back=-1;
    }
    return;
}
void printList(int* q,int n){
    if(front == -1){
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue Elements: ");
    while(n--){
        dequeue(q);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int q[MAX];
    for(int i=0;i<n;i++){
        int t;
        scanf("%d",&t);
        enqueue(q,t);
    }
    display(q);

    return 0;
}