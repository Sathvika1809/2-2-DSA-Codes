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
Node* addNode(Node* head,Node* temp){
    if(head == NULL){
        head = temp;
    }else{
        Node* curr = head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next = temp;
    }
    return head;
}
Node* rearrange(Node* head,int x){
    if(!(head)||!(head->next)){
        return head;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* otherHead = NULL;
    while(curr!=NULL){
        if(curr->data == x){
            if(prev!=NULL){
                prev->next = curr->next;
                Node* temp = curr;
                curr=curr->next;
                temp->next = NULL;
                otherHead = addNode(otherHead,temp);
            }else{
                head = curr->next;
                Node* temp = curr;
                curr = curr->next;
                temp->next = NULL;
                otherHead = addNode(otherHead,temp);

            }
        }else{
            prev = curr;
            curr = curr->next;
        }
    }
    curr = head;
    if(!curr)return otherHead;
    while(curr->next!=NULL){curr=curr->next;}
    curr->next = otherHead;
    return head;
}
int main(){
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    Node* head = NULL;
    while(n--){
        int x;
        scanf("%d",&x);
        head = addtoList(head,x);
    }
    int x;
    printf("Enter the value of x: ");
    scanf("%d",&x);
    head = rearrange(head,x);
    printList(head);

    return 0;
}