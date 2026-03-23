#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;
Node* createNode(int val);
Node* insert(Node* root,Node* newNode);
Node* deleteNode(Node* root,int val);
Node* buildBST(int* a,int n);
void inorderTraversal(Node* root);

Node* createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node* insert(Node* root,Node* newNode){
    if(!root){
        root = newNode;
        return;
    }
    if(root->data<newNode->data){
        if(root->right == NULL){
            root->right = newNode;
        }else{
        root = insert(root->right,newNode);
        }
    }else{
        if(root->left == NULL){
            root->left = newNode;
        }else{
        root = insert(root->left,newNode);
        }
    }
    return root;
}
Node* buildBST(int* a,int n){
    Node* root = NULL;
    for(int i=0;i<n;i++){
        Node* newNode = createNode(a[i]);
        root = insert(root,newNode);
    }
    return root;
}
int checkBST(Node* root){
  Node* curr = root;
  Node* prev;
  int prevval = INT_MIN;
  while(!curr){
    if(curr->left == NULL){
        if(curr->data <= prevval){
            return 0;
        }
        prevval = curr->data;
        curr = curr->right;
    }else{
        prev = curr->left;
        while(prev->right!=NULL && prev->right!=curr){
            prev = prev->right;
        }
        if(prev->right == NULL){
            prev->right = curr;
            curr = curr->left;
        }else{
            prev->right = NULL;
            if(curr->data <=prevval){
                return 0;
            }
            prevval = curr->data;
            curr=curr->right;
        }
    }
  }
  return 1;
}

int main(){
   int n;
   scanf("%d",&n);
   int a[n];
   for(int i=0;i<n;i++){
       scanf("%d",&a[i]);
   }
   Node* root = buildBST(a,n);
   int ans = checkBST(root);
   if(ans){
    printf("True\n");
   }else{
    printf("False\n");
   }
    return 0;
}
