#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
#define MAX_LEN 32
char q[MAX][MAX_LEN];
int front = -1;
int back=-1;
void enqueue(char* str){
    if(front == -1){
        front = back=0;
    }else{
        back++;
    }
    strcpy(q[back],str);
}
void dequeue(char* ans){
    strcpy(ans,q[front]);
    front++;
}
int main(){
    int N;
    scanf("%d",&N);
    enqueue("1");
    for(int i=0;i<N;i++){
        char curr[MAX_LEN];
        dequeue(curr);
        printf("%s ",curr);
        char next0[MAX_LEN],next1[MAX_LEN];
        strcpy(next0,curr);
        strcat(next0,"0");
        strcpy(next1,curr);
        strcat(next1,"1");
        enqueue(next0);
        enqueue(next1);
    }
    return 0;
}