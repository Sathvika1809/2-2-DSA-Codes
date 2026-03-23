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
        root->left = insert(root->left,data);
    }
    else{
        root->right = insert(root->right,data);
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
int findKthLargest(Node* root,int k){
     Node* curr = root;
     int cnt  = 0;
     Node* prev;
     while(curr){
        if(curr->left == NULL&&curr){
            curr = curr->right;
        }
     }



}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    Node* root = buildBST(a,n);
    int k;
    scanf("%d",&k);
    int ans = findKthLargest(root,k);


    return 0;
}

