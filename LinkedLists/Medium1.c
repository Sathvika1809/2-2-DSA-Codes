//Swap kth Nodes IN LinkedList
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;
void printList(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    return;
}
Node* createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
Node* addtoList(Node* head,int val){
    Node* newNode = createNode(val);
    if(!head){
        head = newNode;
    }else{
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = newNode;
    }
    return head;
}
int getLength(Node* head){
    Node* temp = head;
    int len = 0;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}
Node* readList(){
    int n;
    scanf("%d",&n);
    Node* head = NULL;
    while(n--){
        int t;
        scanf("%d",&t);
        head = addtoList(head,t);
    }
    return head;
}
Node* swapkthNodes(Node* head,int k){
    if(!(head)||(!head->next)){
        return head;
    }
    int n = getLength(head);
     if (k > n) return head;
    // if kth from start and end are same, no swap
    if (2*k-1==n) return head;

    Node* left = head;
    Node* right = head;
    Node* prev1 = NULL;
    Node* prev2 = NULL;
    for(int i=1;i<k;i++){
        prev1 = left;
        left = left->next;
    }
    for(int i=1;i<=n-k;i++){
        prev2 = right;
        right = right->next;
    }
    if(prev1){
        prev1->next = right;
    }
    if(prev2){
        prev2->next = left;
    }
    Node* next1 = left->next;
    left->next = right->next;
    right->next = next1;
    if(k==1)head = right;
    if(k==n)head = left;
  
    return head;
}
//Optimal soln one pass
Node* swapkNodes(Node* head,int k){
    Node* curr = head;
    Node* left = NULL;
    Node* right = NULL;
    Node* prev1 = NULL;
    Node* prev2 = NULL;
    int count =1;
    while(curr){
        if(count == k){
            left = curr;
            prev1 = prev2;
            right = head;
        }else if(right){
            prev2 = right;
            right = right->next;
        }
        prev2 = curr;
        curr=curr->next;
        count++;
    }
  
    
}
int main(){
    Node* head = readList();
    int k;
    scanf("%d",&k); 
    head = swapkthNodes(head,k);
    printList(head);
    return 0;
}