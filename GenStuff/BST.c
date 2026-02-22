#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;
Node* createNode(int val);
Node* insertNode(Node* root,int data);
Node* BuildBST(int* a,int n);
void inorderTraversal(Node* root);
void PreorderTraversal(Node* root);
void PostOrderTraversal(Node* root);
void freeTree(Node* root);
Node* deleteNode(Node* root,int val);
Node* createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Out of memory\n");
        return NULL;
    }
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node* insertNode(Node* root,int data){
    if(root == NULL){
        return createNode(data);
    }
    if(data<root->data){
        root->left = insertNode(root->left,data);
    }else{
        root->right = insertNode(root->right,data);
    }
    return root;
}
Node* getNext(Node* curr){
    //get the smallest element in right sub tree to make root
    //whereas u can get largest element in left sub tree to make root i think wait
    curr = curr->right;
    while(curr!=NULL&&curr->left!=NULL)curr = curr->left;
    return curr;
    /*other mthd
    curr= curr->left;
    while(!curr&&!(curr->right))curr = curr->right;
    return curr;
    and then in deleteNode use root->left,x so that u work on left as the left largest is smaller than right so BST prop avails at right we need to make changes at left

    */
}
Node* deleteNode(Node* root,int x){
    if(!root) return root;
    if(root->data > x){
        root->left = deleteNode(root->left,x);
    }else if(root->data<x){
        root->right = deleteNode(root->right,x);
    }
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        //Node with 2 children
        Node* next = getNext(root);
        root->data = next->data;
        root->right = deleteNode(root->right,next->data);
    }
    return root;
    
}
Node* search(Node* root,int x){
    if(root == NULL)return NULL;
    if(root->data == x){
        return root;
    }else if(root->data < x){
        return search(root->right,x);
    }else{
        return search(root->left,x);
    }
    return NULL;
}
int minimum(Node* root){
    if(!root) return -1;
    Node* temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp->data;
}
int maximum(Node* root){
    if(!root) return -1;
    Node* temp = root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp->data;
}
void inorderTraversal(Node* root){
    //left->root->right
    if(root!=NULL){
        inorderTraversal(root->left);
        printf("%d ",root->data);
        inorderTraversal(root->right);
    }
    return;
}
void PreorderTraversal(Node* root){
    //root->left->right
    if(root!=NULL){
        printf("%d ",root->data);
        PreorderTraversal(root->left);
        PreorderTraversal(root->right);
    }
    return;
}
void PostOrderTraversal(Node* root){
    //left->right->root
    if(root!=NULL){
        PostOrderTraversal(root->left); //Visit leftsub tree
        PostOrderTraversal(root->right);//Visit rightsub tree
        printf("%d ",root->data);//Visit root node
    }
    return;
}
void freeTree(Node* root){
    if(root!=NULL){
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
Node* BuildBST(int* a,int n){
    Node* root = NULL;
    for(int i=0;i<n;i++){
        root = insertNode(root,a[i]);
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
    Node* root = BuildBST(a,n);
    inorderTraversal(root);
    printf("\n");
    PreorderTraversal(root);
    printf("\n");
    PostOrderTraversal(root);
    printf("\n");
    printf("%d\n",maximum(root));
    printf("%d\n",minimum(root));
    
    return 0;
}