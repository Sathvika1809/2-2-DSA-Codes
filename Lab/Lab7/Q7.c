#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
int front = -1;
int back = -1;
int q[MAX];
void resetQ(){
    front = -1;
    back = -1;
}
void enqueue(int x){
    if(front == -1){
        front = back = 0;
    }else{
        back++;
    }
    q[back] = x;
}
int main(){
    int N;
    scanf("%d",&N);
    int gas[N];
    int dis[N];
    for(int i=0;i<N;i++){
        scanf("%d",&gas[i]);
    }
    for(int i=0;i<N;i++){
        scanf("%d",&dis[i]);
    }
    int start = 0;
    while(start<N){
        resetQ();
        int currFuel = 0;
        int cnt = 0;
        int idx = start;
        while(cnt<N){
            enqueue(idx);
            currFuel+=gas[idx]-dis[idx];
            if(currFuel<0) break;
            idx = (idx+1)%N;
            cnt++;
        }
        if(cnt == N){
            printf("%d\n",start);
            return 0;
        }
        start++;
    }
    return 0;
}