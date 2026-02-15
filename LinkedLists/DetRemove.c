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
Node* addtoList(Node* head,int temp){
    Node* newNode = createNode(temp);
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
void detecrem(Node* head){
    if(!head||!(head->next)){
        return ;
    }
    Node* fast = head;
    Node* slow = head;
    int fnd = 0;
    while(fast&&fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            fnd = 1;
            break;
        }
    }
    if(!fnd){
        return ;
    }
    slow = head;
    if(slow == fast){
        while(fast->next!=slow){
            fast = fast->next;
        }
    }else{
    while(slow->next!=fast->next){
        slow = slow->next;
        fast = fast->next;
    }
  }
    fast->next = NULL;
}
int main(){
   Node* head = createNode(1);
   head->next = createNode(3);
   Node* temp = head->next;
   temp->next = createNode(4);
   temp->next->next = temp;
   detecrem(head);
   printList(head);
    return 0;
}