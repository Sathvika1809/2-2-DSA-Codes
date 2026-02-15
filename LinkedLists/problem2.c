#include <stdio.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;
int countNodes(Node* head);
int searchElement(Node* head,int key);
Node* insertAtBeginning(Node* head,int val);
Node* insertAtEnd(Node* head,int val);
Node* insertAtPosition(Node* head,int val,int k);
int countNodes(Node* head){
    if(head == NULL){
        return 0;
    }
    Node* temp = head;
    int cnt = 0;
    while(temp!=NULL){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
int searchElement(Node* head,int key){
    Node* temp = head;
    int cnt = 0;
    while(temp!=NULL){
        cnt++;
        if(temp->data == key){
            return cnt;
        }
        temp = temp->next;
    }
    return -1;
}
Node* insertAtBeginning(Node* head,int val){
    Node* newNode = createNode(val);
    newNode->next = head;
    return newNode;
}
Node* insertAtEnd(Node* head,int val){
    Node* newNode = createNode(val);
    Node* temp = head;
    if(head == NULL){
        head = newNode;
    }else{
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}
Node* insertAtPosition(Node* head,int val,int k){
    Node* temp = head;
    Node* next = NULL;
    if(head == NULL){
        return NULL;
    }
    if(k<=0){
        return head;
    }
    if(k == 1){
        Node* newNode = createNode(val);
        newNode->next = head;
        return newNode;
    }
    while(temp!=NULL && k!=1){
        k--;
        temp = temp->next;
    }
    if(temp == NULL){
        return head;
    }
    Node* newNode = createNode(val);
    Node* curr = temp;
    next = curr->next;
    curr->next = newNode;
    newNode->next = next;
    return head;
}





 