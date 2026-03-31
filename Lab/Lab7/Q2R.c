#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
int front = -1;
int back = -1;
int isEmpty(int* q){
    return ((front==-1&&back==-1)||front>back);
}
void enqueue(int* q,int val){
    if(front == -1||front>back){
        front = back = 0;
    }else{
        back++;
    }
    q[back] = val;
    return;
}
void dequeue(){
    front++;
}
int peek(int*q){
    if(front == -1)return -1;
    int val = q[front];
    return val;
}

int main(){
    int q[MAX];
    int freq[26]={0};
    char str[MAX];
    scanf("%s",str);
    int i=0;
    while(str[i]!='\0'){
        freq[str[i]-'a']++;
        enqueue(q,str[i]-'a');
        int done =0;
        while(!isEmpty(q)){
            int ch = peek(q);
            if(freq[ch]==1){
                printf("%c ",ch+'a');
                done = 1;
                break;
            }
            dequeue(q);
        }
        if(done==0){
            printf("-1 ");
        }
        i++;
    }
    return 0;
}