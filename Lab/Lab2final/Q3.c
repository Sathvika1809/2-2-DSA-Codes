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
    newNode->data=val;
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
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}
Node* rotateList(Node* head,int k){
    if(!head||!(head->next)||k==0){
        return head;
    }
    Node* temp = head;
     int n=1;
    while(temp->next!=NULL){
        n++;
        temp = temp->next;
    }
    k=k%n;
    if(k==0)return head;
    temp->next = head;
    temp = head;
    Node* prev = NULL;
    for(int i=0;i<n-k;i++){
        prev = temp;
        temp = temp->next;
    }
    head = temp;
    prev->next = NULL;
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
    Node* head = readList();
    int k;
    scanf("%d",&k);
    head = rotateList(head,k);
    printList(head);
    return 0;
}