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
void findCount(Node* root,int l,int r,int* cnt){
    if(!root)return;
    if(root->data>=l){
        findCount(root->left,l,r,cnt);
    }
    if(root->data >= l && root->data <= r){
        (*cnt)++;
    }
    if(root->data<=r){
        findCount(root->right,l,r,cnt);
    }

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
    int l,r;
    scanf("%d %d",&l,&r);
    int cnt = 0;
    Node* root = buildBST(a,n);
    findCount(root,l,r,&cnt);
    printf("%d\n",cnt);

    return 0;
}