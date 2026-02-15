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
void printList(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int getLength(Node* head){
    Node* temp = head;
    int len =0;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}
int getMiddle(Node* head){
    int n = getLength(head);
    Node* fast = head->next;
    Node* slow = head;
    while(fast!=NULL&&fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    if(n%2==1){
        return slow->data;
    }else{
        return slow->next->data;
    }
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
    Node* head = readList();
    int middle = getMiddle(head);
    printf("%d",middle);
    return 0;
}