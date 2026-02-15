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
    return head;
}
Node* addNode(Node* head,Node* newNode){
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
void merge(Node* head1,Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* next1 = NULL;
    Node* next2 = NULL;
    while(temp1!=NULL && temp2!=NULL){
        next1 = temp1->next;
        next2 = temp2->next;
        temp2->next = temp1->next;
        temp1->next = temp2;
        temp1 = next1;
        temp2 = next2;
    }
    head2 = temp2;
    printList(head1);
    printf("\n");
    printList(head2);
}
int countOccurences(Node* head,int key){
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        if(temp->data == key){
            count++;
        }
        temp = temp->next;
    }
    return count;
}
int main(){
    Node* head1 = readList();
    // Node* head2 = readList();
    // merge(head1,head2);
    int key = 1;
    printf("%d",countOccurences(head1,key));
    return 0;
}