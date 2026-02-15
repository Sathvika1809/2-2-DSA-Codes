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
}
Node* createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
Node* addtoList(Node* head,int temp){
    Node* newNode = createNode(temp);
    if(head == NULL){
        head = newNode;
    }
    else{
        Node* curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = newNode;
    }
    return head;
}
Node* mergeLists(Node* head1,Node* head2){
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;
    while(head1!=NULL&&head2!=NULL){
        if(head1->data < head2->data){
        tail->next = createNode(head1->data);
        head1 = head1->next;
        }else if(head1->data>head2->data){
          tail->next = createNode(head2->data);
          head2 = head2->next;
        }else{
            tail->next = createNode(head1->data);
            head1 = head1->next;
            head2 = head2->next;
        }
        tail = tail->next;
    }
    while(head1!=NULL){
        tail->next = createNode(head1->data);
        tail = tail->next;
        head1 = head1->next;
    }
    while(head2!=NULL){
       tail->next = createNode(head2->data);
       tail = tail->next;
       head2 = head2->next;
    }
    return dummy.next;
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
int main(){
    Node* head1 = readList();
    Node* head2 = readList();
    Node* head3 = mergeLists(head1,head2);
    printList(head3);
    return 0;

}