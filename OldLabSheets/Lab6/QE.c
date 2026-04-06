#include <stdio.h>
#include <stdlib.h>
#define MAX 100000
int front = 5001;
int back = 5000;
int dq[MAX];
void push_front(int val){
    dq[--front]=val;
    return;
}
void push_back(int val){
    dq[++back] = val;
    return;
}
void pop_front(){
    front++;
}
void pop_back(){
    back--;
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
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<k;i++){
        while(!isEmpty()&&a[get_back()]<=a[i]){
            pop_back();
        }
        push_back(i);
    }
    int ans[MAX];
    int idx = 0;
    ans[idx++] = a[get_front()];
    for(int i=k;i<n;i++){
        while(!isEmpty()&&get_front()<=i-k){
            pop_front();
        }
        while(!isEmpty()&&a[get_back()]<=a[i]){
            pop_back();
        }
        push_back(i);
        ans[idx++] =a[get_front()];
    }
    for(int i=0;i<idx;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}
