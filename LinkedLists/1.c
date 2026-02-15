#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;
Node* createNode(int data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
Node* addtoList(Node* head,int val){
    Node* newNode = createNode(val);
    if(head == NULL){
        newNode->next = newNode;
        return newNode;
    }
    Node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}
//reverse
Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return head;
}
Node* reversefun(Node* head){
    return reverseUtil(head,NULL);
}
//Tail recursive
Node* reverseUtil(Node* curr,Node* prev){
    if(curr==NULL){
        return prev;
    }
    Node* next = curr->next;
    curr->next = prev;
    return reverseUtil(next,curr);
}
//Recursive reverse
Node* reverse(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL; 
    return newHead;
}
//Optimal Addhead
Node* addHead(Node* head,int temp){
    Node* newNode = createNode(temp);
    if(head == NULL){
        return newNode;
    }
    newNode->next = head;
    return newNode;
}
//Optimal Read List
Node* readList(){
    int n;
    scanf("%d",&n);
    Node* head = NULL;
    while(n--){
        int temp;
        scanf("%d",&temp);
        head = addHead(head,temp);
    }
    head = reverse(head);
    return head;
}

Node* readList(){
    int n;
    scanf("%d",&n);
    Node* head = NULL;
    while(n--){
        int temp;
        scanf("%d",&temp);
        head = addtoList(head,temp);
    }
    return head;
}
void traversal(Node* head){
    if(head==NULL){
        return;
    }
    Node* temp = head;
    do{
        printf("%d ",temp->data);
        temp = temp->next;
    }while(temp!=head);
    return;
}
int main(){
    Node* head = readList();
    traversal(head);
}