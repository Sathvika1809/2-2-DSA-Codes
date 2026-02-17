#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 1000
int topIdx=-1;
int isEmpty(int* st){
    return topIdx==-1;
}
void push(int* st,int val){
    if(topIdx == MAX_SIZE-1) return;
    st[++topIdx]=val;
    return;
}
void pop(int* st){
    if(isEmpty(st)){
        return;
    }
    int topp = st[topIdx];
    topIdx--;
    return;
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
    int seq1[n];
    for(int i=0;i<n;i++){
    scanf("%d",&seq1[i]);
    }
    int seq2[n];
    for(int i=0;i<n;i++){
    scanf("%d",&seq2[i]);
    }
    int k=0;
    int i=0;
    while(i<n||!isEmpty(stk)){
        if(!isEmpty(stk)&&k<n&&top(stk)==seq2[k]){
            printf("Pop\n");
            pop(stk);
            k++;
        }else if(i<n){
            push(stk,seq1[i++]);
            printf("Push\n");   
        } else{
            break;
        }
    } 
    
    if(k!=n||!isEmpty(stk)){
        printf("Impossible\n");
    }
    return 0;
}