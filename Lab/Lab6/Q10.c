#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* down;
    struct Node* right;
}Node;
Node* createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->down = NULL;
    newNode->right = NULL;
    newNode->data =val;
    return newNode;
}
void print(Node* head){
    if(!head){
        printf("\n");
        return;
    }
    Node* curr = head;
    while(curr){
        if(curr!=head){
            printf(" -> %d",curr->data);
        }else{
            printf("%d",curr->data);
        }
        curr = curr->right;
    }
    printf("\n");
    if(head->down)printf("|\n");
    return;
}

int main(){
    int v;
    scanf("%d",&v);
    int adj[v][v];
    Node* list[v];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            scanf("%d",&adj[i][j]);
        } 
    }
    for(int i=0;i<v;i++){
        Node* temp = createNode(i);
        for(int j=0;j<v;j++){
            if(adj[i][j]==1){
                Node* newNode = createNode(j);
                Node* zero = temp;
                while(zero->right)zero = zero->right;
                zero->right =newNode;
            }
        }
        list[i]=temp;
        if(i!=0) list[i-1]->down = temp;
    }
    printf("\n");
    for(int i=0;i<v;i++){
        print(list[i]);
    }

    return 0;
}