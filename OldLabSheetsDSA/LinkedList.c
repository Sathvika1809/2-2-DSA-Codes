#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct Node_t{
    int data;
    struct Node_t* next;
}Node;
Node* createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    assert(newNode!=NULL);
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
Node* addToList(Node* head,int val){
    Node* newNode = createNode(val);
    if(head == NULL){
        return newNode;
    }
    Node* curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = newNode;
    return newNode;
}
Node* readList(){
    int n;
    scanf("%d",&n);
    Node* head = NULL;
    for(int i=0;i<n;i++){
        int val;
        scanf("%d",&val);
        if(head == NULL){
        head = addToList(head,val);
        }
        else{
            addToList(head,val);
        }
    }
    return head;
}
void printList(Node* head){
    Node* ptr = head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return;
}
void freeList(Node* head){
    Node *curr,Node* nxt;
    curr= head;
    while(curr!=NULL){
        nxt = curr->next;
        free(curr);
        curr = nxt;
    }
}
Node* addNode(Node* head,Node* newNode){
    if(head ==NULL){
        head = newNode;
    }else{
        Node* temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = newNode;
    }
    return newNode;
}