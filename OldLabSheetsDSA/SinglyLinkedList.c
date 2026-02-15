#include <stdio.h>
#include <stdlib.h>
typedef struct Node_t{
    int data;
    struct Node_t* next;
}Node;

Node* createNode(int val);
Node* addtoList(Node*head ,int val);
Node* addNode(Node* head,Node* newNode);
Node* readList();
Node* reverse(Node* head);
void printList(Node* head);
Node* rotate(Node* head,int k);
int lenList(Node* head);
int lenlist(Node* head){
    Node* curr = head;
    int len = 0;
    while(curr){
        len++;
        curr = curr->next;
    }
    return len;
}
Node* addNode(Node* head,Node* newNode){
    if(head == NULL){
        head = newNode;
    }else{
        Node* curr = head;
        curr->next = newNode;
    }
    return head;
}
Node* rotate(Node *head,int k){
    int n = lenlist(head);
    k = (k%n);
    if(k == 0){
        return head;
    }
    Node* slow = head;
    Node* fast = head;
    int kcpy = k;
    while(kcpy--){
        fast = fast->next;
    }
    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }
    Node* newHead = slow->next;
    slow->next = NULL;
    fast->next = head;
    return newHead;
}
void printList(Node* head){
    if(head == NULL){
        printf("0");
    }
    while(head->next!=NULL){
        printf("%d ",head->data);
        head = head->next;
    } 
}
Node* createNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
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
Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = curr->next;
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
int main(){
    Node* list = readList();
    int k;
    scanf("%d",&k);
    list = rotate(list,k);
    printList(list);
    return 0;
}





