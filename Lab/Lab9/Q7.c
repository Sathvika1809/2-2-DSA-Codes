#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;
int cnt = 0;
int k;
void inorderTraversal(Node* root){
    
    if(!root) return;
    inorderTraversal(root->left);
    cnt++;
    if(cnt==k){
    printf("%d ",root->data);
    }
    inorderTraversal(root->right);
    return;
}
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
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&k);
    Node* root = buildBST(a,n);
    inorderTraversal(root);

}