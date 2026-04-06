#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
int front = -1;
int back = -1;
int isEmpty(int* q){
    return (front==-1&&back==-1)||(front>back);
}
void enqueue(int* q,int val){
    if(front==-1){
        front = back = 0;
    }else{
        back++;
    }
    q[back]=val;
    return;
}
void dequeue(){
    front++;
}
int peek(int* q){
    if(isEmpty(q)){
        return -1;
    }else{
        return q[front];
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    int q[MAX];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int maxm = a[0];
    for(int i=1;i<n;i++){
        if(a[i]>maxm){
            maxm = a[i];
        }
    }
    int freq[maxm+1];
    
    for(int i = 0; i <= maxm; i++){
         freq[i] = 0;
   }
    for(int i=0;i<n;i++){
        freq[a[i]]++;
        enqueue(q,a[i]);
        int done = 0;
        while(!isEmpty(q)){
            int x = peek(q);
            if(freq[x]==1){
                printf("%d ",x);
                done = 1;
                break;
            }
            dequeue(q);
        }
        if(done==0){
                printf("-1 ");
        }
    }
    return 0;
}