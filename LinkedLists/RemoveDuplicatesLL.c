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
    return prev;
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
Node* removeDuplicates(Node* head){
    if(head == NULL){
        return head;
    }
    Node* temp = head;
    Node* prev =  NULL;
    int hash[256];
    for(int i=0;i<256;i++){
        hash[i]=0;
    }
    while(temp!=NULL){
        if(hash[temp->data]==1){
          prev->next = temp->next;
          free(temp);
          temp = prev->next;
        }else{
            hash[temp->data]=1;
            prev = temp;
            temp = temp->next;
        }
    }

    return head;

}
int main(){
    Node* head = readList();
    Node* result = removeDuplicates(head);
    printList(result);

    return 0;
}