#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;


Node* createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root,int val){
    
    if(!root) return createNode(val);
    if(root->data<val){
       
         root->right = insert(root->right,val);
        
    }else if(root->data>val){
        
        root->left = insert(root->left,val);
        
    }
    return root;
}

Node* buildBST(int* a,int n){
    Node* root = NULL;
    for(int i=0;i<n;i++){
        root = insert(root,a[i]);
    }
    return root;
}
int front = -1;
int back = -1;

Node* q[1000];
void enqueue(Node* x){
    if(front == -1){
        front = back = 0;
    }else{
        back++;
    }
        q[back]=x;
}
void dequeue(){
    front++;
}
int isEmpty(){
    return (front==-1&&back==-1)||(front>back);
}


int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    Node* root = buildBST(a,n);
    enqueue(root);
    int dir = 1;
    while(!isEmpty()){
        int l = front;
        int r = back;
        int size = r-l+1;
        Node* temp[10000];
        for(int i=0;i<size;i++){
            temp[i] = q[front+i];
        }
        if(dir==1){
            for(int i=0;i<size;i++){
                printf("%d ",temp[i]->data);
            }
        }else{
            for(int i=size-1;i>=0;i--){
                printf("%d ",temp[i]->data);
            }
        }
    
    for(int i=0;i<size;i++){
        if(temp[i]->left) enqueue(temp[i]->left);
        if(temp[i]->right)enqueue(temp[i]->right);
    }
    for(int i=0;i<size;i++){
        dequeue();
    }
        dir*=-1;
    
}
    printf("\n");
    return 0;
}