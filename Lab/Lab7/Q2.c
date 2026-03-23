#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int front = -1;
int back = -1;

int isEmpty(int* q){
    return (front == -1 && back == -1)||(front>back);
}
void enqueue(int* q,int x){
    if(front == -1||front>back){
        front = back = 0;
    }else{
        back++;
    }
    q[back] = x;
}
int peek(int* q){
    if(front == -1)return -1;
    char val = q[front];
    return val;
}
void dequeue(int* q){
    front++;
}
int main(){
    char str[MAX];
    int q[MAX];
    int freq[26] = {0};
    scanf("%s",str);
    int i=0;
    while(str[i]!='\0'){
        freq[str[i]-'a']++;
        enqueue(q,str[i]-'a');
        int done = 0;
        while(!isEmpty(q)){
            int ch = peek(q);
            if(freq[ch]==1){
                done = 1;
                printf("%c ",ch+'a');
                break;
            }
            dequeue(q);
        }
        if(!done) printf("-1 ");
        i++;
    }
    printf("\n");
    return 0;
}