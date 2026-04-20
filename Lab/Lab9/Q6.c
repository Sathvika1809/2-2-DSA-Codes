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
int find(Node* root,int x,int* path,int idx){
    if(!root)return -1;

    path[idx++] = root->data;
    if(x==root->data){
        return idx;
    }else if(x<root->data){
        return find(root->left,x,path,idx);
    }else{
        return find(root->right,x,path,idx);
    }
    return 0;
}
int findSum(Node* root,int A,int B){
    int a[1000];
    int b[1000];
    int aa = find(root,A,a,0);
    int bb = find(root,B,b,0);
    int idx = 0;
    for(int i=0;i<aa&&i<bb;i++){
        if(a[i]==b[i]){
            idx = i;
        }
    }
    int ans = a[idx];
    for(int i=idx+1;i<aa;i++){
        ans+=a[i];
    }
    for(int i=idx+1;i<bb;i++){
        ans+=b[i];
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
    int A,B;
    scanf("%d %d",&A,&B);
    Node* root = buildBST(arr,n);
    int sum = findSum(root,A,B);
    printf("%d\n",sum);



    return 0;
}