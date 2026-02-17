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
    printf("\n");
    return;
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
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}
Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
Node* addNode(Node* head,Node* newNode){
    if(!head){
        return newNode;
    }
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    
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
Node* swapNodes(Node* head){
    if(!head||!(head->next)) return head;
    Node* one = head;
    Node* two = one->next;
    one->next = swapNodes(two->next);
    two->next = one;
    return two;
    
}
int main(){
  Node* head = readList();
  head = swapNodes(head);
  printList(head);
}