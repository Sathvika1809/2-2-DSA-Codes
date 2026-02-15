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
Node* getMiddle(Node* head){
    if(!head||!(head->next)){
        return head;
    }
    Node* fast = head->next;
    Node* slow = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
    
}
Node* merge(Node* left,Node* right){
    Node* newList = NULL;
    while(left&&right){
        if(left->data<right->data){
            newList = addtoList(newList,left->data);
            left=left->next;
        }else if(right->data<left->data){
            newList = addtoList(newList,right->data);
            
            right = right->next;
        }else{
            newList = addtoList(newList,left->data);
            left = left->next;
            right = right->next;
        }
    }
    while(left){
        newList = addtoList(newList,left->data);
        left=left->next;
    }
    while(right){
        newList = addtoList(newList,right->data);
        right=right->next;
    }
    return newList;
  
}
Node* mergesort(Node* head){
    if(!head||(!head->next)){
        return head;
    }
    Node* left = head;
    Node* mid = getMiddle(head);
    Node* right = mid->next;
    mid->next = NULL;
    left = mergesort(left);
    right = mergesort(right);
    merge(left,right);
}

int main(){
Node* head = readList();
head = mergesort(head);
printList(head);

    return 0;
}
