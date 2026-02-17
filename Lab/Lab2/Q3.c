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
        head = newNode;
    }else{
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    return head;
}
Node* rotateList(Node* head,int k){
    if(head==NULL || head->next == NULL || k==0){
        return head;
    }
    Node* tail = head;
    int len = 1;
    while(tail->next!=NULL){
        tail = tail->next;
        len++;
    }
    tail->next = head;
    int cnt=1;

    Node* temp = head;
    while(cnt < len-k){
        temp=temp->next;
        cnt++;
    }
    head = temp->next;
    temp->next = NULL;
    return head;
}
int main(){
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    int size = n;
    Node* head = NULL;
    while(n--){
        int x;
        scanf("%d",&x);
        head = addtoList(head,x);
    }
    int k;
    printf("Enter the number of rotations: ");
    scanf("%d",&k);
    k=k%size;
    head = rotateList(head,k);
    printList(head);
}