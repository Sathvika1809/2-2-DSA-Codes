#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* right,*down;
}Node;
void printList(Node* head){
    Node* currRow = head;
    while(currRow!=NULL){
        Node* currCol = currRow;
        while(currCol!=NULL){
            printf("%d ",currCol->data);
            currCol = currCol->right;
        }
        printf("\n");
        currRow = currRow->down;
    }
}
Node* createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->right = NULL;
    newNode->down = NULL;
    return newNode;
}

Node* constructMatrix(int n,int a[n][n]){
    Node* nodes[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            nodes[i][j] = createNode(a[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j+1<n){
                nodes[i][j]->right = nodes[i][j+1];
            }
            if(i+1<n){
                nodes[i][j]->down = nodes[i+1][j];
            }
        }
    }
        return nodes[0][0];//return head;
    
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    Node* head = constructMatrix(n,a);
    printList(head);
    return 0;
}