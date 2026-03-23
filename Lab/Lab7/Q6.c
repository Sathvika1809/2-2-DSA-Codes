#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
int front = -1;
int back = -1;
typedef struct{
    int ff;
    int ss;
}Pair;
Pair q[MAX];
void enqueue(int x,int y){
    if (front == -1){
        front = back = 0;
    }else{
        back++;
    }
    q[back].ff = x;
    q[back].ss = y;
}
Pair dequeue(){
    return q[front++];
}
int isEmpty(){
    return (front == -1||front>back);
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int x;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        enqueue(i,x);
    }
    int ans=0;
    while(!isEmpty(q)){
        Pair curr = dequeue();
        ans++;
        if(curr.ss !=1){
            enqueue(curr.ff,curr.ss-1);
        }else{
            if(curr.ff == k){
                printf("%d\n",ans);
                return 0;
            }
        }
    }
    
    return 0;
}