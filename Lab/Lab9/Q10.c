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
Node* find(Node* root,int x){
    if(root->data == x||!(root)){
        return root;
    }
    if(root->data<x){
        return find(root->right,x);
    }else{
        return find(root->left,x);
    }
}
int FindSum(Node* root){
   if(!root)return 0;
   int ans = 0;
   ans+=root->data;
   ans+=FindSum(root->left);
   ans+=FindSum(root->right);
   return ans;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    Node* root = buildBST(a,n);
    int x;
    scanf("%d",&x);
    printf("%d\n",FindSum(find(root,x)));




    return 0;
}