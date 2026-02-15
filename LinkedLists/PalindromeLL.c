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
Node* addtoList(Node* head,int val){
    Node* newNode = createNode(val);
    if(!head){
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
Node* reverse(Node* head){
    if(!head||!(head->next)){
        return head;
    }
    Node* newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}
Node* readList(){
    int n;
    scanf("%d",&n);
    Node* head = NULL;
    while(n--){
        int t;
        scanf("%d",&t);
        head = addtoList(head,t);
    }
    return head;
}
Node* getMid(Node* head){
    if(!head||!(head->next)){
        return head;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast&&fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int palindrome(Node* head){
    if(!head||!(head->next)){
        return 1;
    }
    Node* temp = head;
    Node* mid = getMid(head);
    Node* curr = reverse(mid->next);
    mid->next = NULL;
    while(curr!=NULL){
        if(temp->data!=curr->data){
            return 0;
            break;
        }
        curr = curr->next;
        temp=temp->next;
    }
    return 1;
}
int main(){
    Node* head = readList();
    int a = palindrome(head);
    a==1?printf("True"):printf("False");
    
    return 0;
}