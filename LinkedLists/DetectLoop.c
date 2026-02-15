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
// Node* readList(){
//     int n;
//     scanf("%d",&n);
//     Node* head = NULL;
//     while(n--){
//         int temp;
//         scanf("%d",&temp);
//         head = addtoList(head,temp);
//     }
//     return head;
// }
//Floyd Cycle Finding Algorithm
int DetectLoop(Node* head){
    if(!head && !head->next){
        return 0;
    }
    Node* fast = head;
    Node* slow = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            return 1;
            break;
        }
    }
    return 0;
}
int main(){
    Node* head = createNode(1);
    head->next = createNode(3);
    head->next->next = createNode(4);
    head->next->next->next = head->next;
    if(DetectLoop(head)){
        printf("true");
    }else{
        printf("false");
    }
    return 0;
}