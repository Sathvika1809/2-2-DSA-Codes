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
int findMaxDepth(Node* root){

    if(!root)return 0;
    int l = findMaxDepth(root->left);
    int r = findMaxDepth(root->right);
    return (l>r?l:r)+1;
}
//Level Order Traversal is also a option using queues
int search(Node* root,int key){
    if(!root)return 0;
    if(root->data==key){
        return 1;
    }else if(root->data<key){
        return search(root->right,key);
    }else{
        return search(root->left,key);
    }
}
//Using Iterative approach
int searchIter(Node* root,int key){
    int ans = 0;
    while(root!=NULL){
    if(root->data == key){
        ans = 1;
        break;
    }else if(root->data < key){
        root = root->right;
    }else{
        root = root->left;
    }
}
return ans; 
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    Node* root = buildBST(arr,n);
    int ans = findMaxDepth(root);
    printf("%d\n",ans);
    int key;
    scanf("%d",&key);
    int a = search(root,key);
    int aiter = searchIter(root,key);
    printf("%d %d",a,aiter);
    return 0;
}