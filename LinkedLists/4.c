#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
Node* addtoList(Node* head,int val){
    Node* newNode = createNode(val);
    if(head == NULL){
        return newNode;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}
void printList(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
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
Node* swapInPairs(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* one = head;
    Node* two = one->next;
    Node* newHead=two->next;
    two->next = one;
    one->next = swapInPairs(newHead);  
    return two;
}
int main(){
    Node* head = readList();
    Node* temp = swapInPairs(head);
    printList(temp);
    return 0;
}