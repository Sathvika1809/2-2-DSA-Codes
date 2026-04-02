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

int findFloor(Node* root,int val){
    int ans = -1;
    while(root){
        if(root->data == val){
            return root->data;
        }else if(root->data < val){
            ans = root->data;
            root = root->right;
        }else{
            root = root->left;
        }
    }
    return ans;
}
Node* insert(Node* root,int val){
    Node* newNode  = createNode(val);
     if(!root) return newNode;
    if(root->data<val){
        if(root->right==NULL){
            root->right = newNode;
        }else{
            root->right = insert(root->right,val);
        }
    }
    if(root->data>val){
        if(root->left == NULL){
            root->left = newNode;
        }else{
            root->left = insert(root->left,val);
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
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    Node* root = buildBST(a,n);
    int val;
    scanf("%d",&val);
    int ans = findFloor(root,val);
    printf("%d\n",ans);

    return 0;
}