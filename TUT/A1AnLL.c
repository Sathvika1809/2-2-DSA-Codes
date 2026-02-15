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
    if(!(head)||!(head->next)){
        return head;
    }
    Node* newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}
Node* getMid(Node* head){
    Node* fast = head->next;
    Node* slow = head;
    while(fast&&fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node* rearrange(Node* head){
    Node* temp= head;
    Node* mid = getMid(head);
    Node* right = reverse(mid->next);
    mid->next = NULL;
    Node* next1;
    Node* next2;
    while(temp!=NULL&&right!=NULL){
        next1 = temp->next;
        next2 = right->next;
        right->next = next1;
        temp->next = right;
        temp = next1;
        right = next2;
    }
    return head;
}
Node* readList(){
    int n;
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
    head = rearrange(head);
    printList(head);
    return 0;
}