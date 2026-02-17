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
}Node* createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
Node* addtoList(Node* head,int val){
    Node* newNode = createNode(val);
    if(head == NULL){
        head = newNode;
    }else{
        Node* temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = newNode;
    }
    return head;
}
Node* readList(){
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    Node* head = NULL;
    while(n--){
        int x;
        scanf("%d",&x);
        head = addtoList(head,x);
    }
    return head;
}
Node* increasing(Node* head){
    Node* temp = head;
    while(temp->next!=NULL){
        if(temp->data>=temp->next->data){
            temp->next = temp->next->next;
            if(temp->next == NULL){
                return head;
            }
            temp = temp->next;
        }else{
            temp = temp->next;
        }
    }
}
int main(){
    Node* head = readList();
    head = increasing(head);
    printList(head);
    return 0;
}