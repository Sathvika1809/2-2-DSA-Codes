#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int val);
Node* insert(Node* root,int val);
Node* findMin(Node* root);
Node* deleteNode(Node* root,int val);
Node* findMin(Node* root){
    while(root->left!=NULL){
        root = root->left;
    }
    return root;
}
Node* deleteNode(Node* root,int val){
    if(root == NULL) return root;
    if(val < root->data){
        root->left = deleteNode(root->left,val);
    }else if(val > root->data){
        root->right = deleteNode(root->right,val);
    }
    else{
        if(root->right==NULL){
            Node* temp = root->left;
            free(root);
            root = temp;
        }else if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            root = temp;
        }else{
            Node* temp = root;
            Node* small = findMin(root->right);
            root->data = small->data;
            root->left = deleteNode(root->right,temp->data);
        }
    }
}



int main(){







    return 0;
}