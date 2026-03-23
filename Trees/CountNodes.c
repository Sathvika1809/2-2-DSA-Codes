#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;
Node* createNode(int val);
Node* insert(Node* root,int data);
Node* buildBST(int* a,int n);
Node* createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node* insert(Node* root,int data){
    
    
    if(!root){
        return createNode(data);
    }
    if(root->data > data){
        else{
        root->left = insert(root->left,data);
        }
    }else{
        if(root->right == NULL){
            root->right = newNode;
        }else{
            root->right = insert(root->right,data);
        }
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
int countNodes(Node* root,int min,int max){
  
    if(!root)return 0;
    if(root->data == max &&root->data ==min)return 1;
    if(root->data >=min && root->data<=max){
        return 1+countNodes(root->left,min,max)+countNodes(root->right,min,max);
    }
    if(root->data<min){
        if(root->right==NULL){
            return 0;
        }else{
           return countNodes(root->right,min,max);
        }
    }else{
        if(root->left == NULL){
            return 0;
        }else{
        return countNodes(root->left,min,max);    
    }
}
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    Node* root = buildBST(arr,n);
    int min,max;
    printf("Enter the range values:\n");
    scanf("%d %d",&min,&max);
    int ans = countNodes(root,min,max);


    return 0;
}