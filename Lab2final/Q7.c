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
Node* addNode(Node* head,Node* newNode){
    if(!head){
        return newNode;
    }
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    
    return head;
}
Node* rearrange(Node* head,int x){
   Node* prev = NULL;
   Node* curr = head;
   Node* otherHead = NULL;
   Node* temp;
    while(curr){
        if(curr->data==x){
            if(prev){
                prev->next = curr->next;
                temp = curr;
                curr = curr->next;
                temp->next = NULL;
                otherHead=addNode(otherHead,temp);
            }
            else{
                head = curr->next;
                temp = curr;
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
    if(!curr){
        return otherHead;
    }
    while(curr->next){
        curr = curr->next;
    }
    curr->next = otherHead;
    return head;
}

int main(){
    int n;
    scanf("%d",&n);
    Node* head = NULL;
    while(n--){
        int temp;
        scanf("%d",&temp);
        head = addtoList(head,temp);
    }
    int x;
    scanf("%d",&x);
    head = rearrange(head,x);
    printList(head);
    return 0;
}