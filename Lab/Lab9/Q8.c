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
Node* leftmost(Node* temp){
    while(temp&&temp->left!=NULL){
        temp = temp->left;
    }
    return temp;
}
Node* find(Node* root,int x){
    Node* succ = NULL;
    Node* curr = root;

    while(curr){
        if(x<curr->data){
            succ = curr;
            curr = curr->left;
        }else if(x>curr->data){
            curr = curr->right;
        }else{ // if match root go to leftmost right sub tree
            if(curr->right != NULL){
                return leftmost(curr->right);
            }
            return succ;
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
    int x;
    scanf("%d",&x);
    Node* root = buildBST(a,n);
    Node* ans = find(root,x);
    if(ans == NULL){
        printf("-1\n");
    }else{
    printf("%d\n",ans->data);
    }
    return 0;
}
