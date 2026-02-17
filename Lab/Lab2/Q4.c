#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int val);
void printList(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
Node* createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
Node* addtoList(Node* head,int val){
    Node* newNode = createNode(val);
    if(head==NULL){
        head= newNode;
    }else{
        Node* temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = newNode;
    }
    return head;
}
Node* modifyList(Node* head){
    // if(head == NULL || head->next==NULL){
    //     return head;
    // }
    // Node* first = head;
    // Node* second = head->next;
    // int sum = first->data+second->data;
    // Node* newNode = createNode(sum);
    // newNode->next = second->next;
    // second->next = newNode;
    // modifyList(newNode->next);
    // return head;
    if(head == NULL || head->next ==NULL){
        return head;
    }
    Node* temp = head;
    while(temp!=NULL){
    if(temp->next == NULL){
        return head;
    }
    Node* one = temp;
    Node* two = temp->next;
    int sum = one->data+two->data;
    Node* ans = createNode(sum);
    ans->next = two->next;
    two->next = ans;
    temp = ans->next;
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
int main(){
    Node* head = readList();
    head = modifyList(head);
    printList(head);
    return 0;
}