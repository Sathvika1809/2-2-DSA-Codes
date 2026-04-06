#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int val);
Node* insert(Node* root,Node* newNode);
//Node* deleteNode(Node* root,int val);
Node* buildBST(int* a,int n);
void inorderTraversal(Node* root);
void inorderTraversal(Node* root){
    if(!root) return;
    inorderTraversal(root->left);
    printf("%d ",root->val);
    inorderTraversal(root->right);
    return;
}
Node* insert(Node* root,Node* newNode){
    if(root == NULL){
        root=newNode;
        return root;
    }
    if(root->val<newNode->val){
        if(root->right==NULL){
            root->right = newNode;
        }else{
        root->right = insert(root->right,newNode);
        }
    }else{
        if(root->left == NULL){
            root->left = newNode;
        }else{
        root->left = insert(root->left,newNode);
    }
}
return root;
}
Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node* buildBST(int* a,int n){
    Node* root = NULL;
    for(int i=0;i<n;i++){
        Node* newNode = createNode(a[i]);
        root = insert(root,newNode);
    }
    return root;
}
Node* findLCA(Node* root,int u,int v){
    if(!root){
        return NULL;
    }
    if(u<root->val && v<root->val){
        return findLCA(root->left,u,v);
    }
    if(u>root->val && v>root->val){
        return findLCA(root->right,u,v);
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
    int u,v;
    scanf("%d %d",&u,&v);
    Node* root = buildBST(a,n);
    Node* one = findLCA(root,u,v);
    printf("%d\n",one->val);

    return 0;
}