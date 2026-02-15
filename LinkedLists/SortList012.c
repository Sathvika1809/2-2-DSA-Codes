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
        newNode->next = NULL;
    }else{
        Node* temp =head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
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
Node* sortLL(Node* head){
    if(!head || !(head->next)){
        return head;
    }
    Node* zero = NULL;
    Node* one = NULL;
    Node* two = NULL;
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data == 1){
            one = addNode(one,temp);
        }else if(temp->data == 0){
            zero =addNode(zero,temp);
        }else{
            two = addNode(two,temp);
        }
    }
    while(temp)
}
int main(){
    Node* head = readList();


    return 0;
}