#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;
int main(){
    int n;
    scanf("%d",&n);
    int a1[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a1[i]);
    }
    int a2[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a2[i]);
    }
    


    return 0;
}