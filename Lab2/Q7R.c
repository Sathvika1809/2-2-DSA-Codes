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
        temp=temp->next;
    }
    return;
}
Node* createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
Node* addtoList(Node* head,int t){
    Node* newNode = createNode(t);
    if(!head){
        head=newNode;
    }else{
        Node* temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = newNode;
    }
    return head;
}
Node* addNode(Node* head,Node* newNode){
    if(!head){
        return newNode;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = newNode;
    return head;
}
Node* rearrange(Node* head,int x){
    Node* prev = NULL;
    Node* curr = head;
    Node* newList = NULL;
    while(curr){
    if(curr->data==x){
    if(!prev){
        head = curr->next;
        Node* temp = curr;
         curr = curr->next;
        temp->next = NULL;
        newList = addNode(newList,temp);
    }else{
        prev->next = curr->next;
        Node* temp = curr;
        curr = curr->next;
        temp->next = NULL;
        newList = addNode(newList,temp);
    }
   }else{
    prev = curr;
    curr = curr->next;
    }
}
curr = head;
if(!curr) return newList;
while(curr->next){
    curr=curr->next;
}
curr->next = newList;
return head;
}
Node* readList(){
    int n;
    scanf("%d",&n);
    Node* head = NULL;
    while(n--){
        int x;
        scanf("%d",&x);
        head = addtoList(head,x);
    }
    return head;
}
int main(){
    Node* head = readList();
    int x;
    scanf("%d",&x);
    head = rearrange(head,x);
    printList(head);
    return 0;
}