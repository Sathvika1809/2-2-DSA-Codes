#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
int front = 5001;
int back = 5000;
int dq[10000];
void push_front(int x){
    dq[--front] = x;
}
void push_back(int x){
    dq[++back] = x;
}
void pop_back(){
    back--;
}
void pop_front(){
    front++;
}
int get_front(){
    return dq[front];
}
int get_back(){
    return dq[back];
}
int isEmpty(){
    return front>back;
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<k;i++){
        while(!isEmpty()&&arr[get_back()]<=arr[i]){
            pop_back();
        }
        push_back(i);
    }
    int ans[10000];
    int idx = 0;
    ans[idx++] = arr[get_front()];
    for(int i=k;i<n;i++){
        while(!isEmpty()&&get_front()<=i-k){
            pop_front();
        }
        while(!isEmpty()&&arr[get_back()]<=arr[i]){
            pop_back();
        }
        push_back(i);
        ans[idx++] = arr[get_front()];
    }
    for(int i=0;i<idx;i++){
        printf("%d " ,ans[i]);
    }
    printf("\n");
    return 0;
}