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
            temp=temp->next;
        }
        temp->next = newNode;
    }
    return head;
}
// Node* increasing(Node* head){
//     Node* temp = head;
//     while(temp->next!=NULL){
//         if(temp->data>=temp->next->data){
//             temp->next = temp->next->next;
//             if(temp->next==NULL){
//                 return head;
//             }
//             temp=temp->next;
           
//         }else{
//             temp=temp->next;
//         }
//     }
//     return head;
// }
Node* increasing(Node* head){
    if(!head||(!head->next)){
        return head;
    }
    Node* prev=head;
    Node* curr = head->next;
    while(curr){
        if(curr->data>prev->data){
            prev=curr;
            curr=curr->next;
        }else{
            prev->next = curr->next;
            Node* toDispose = curr;
            curr = curr->next;
            toDispose->next = NULL;
            free(toDispose);
        }
    }
    return head;
}
Node* readList(){
    int n;
    scanf("%d",&n);
    Node* head = NULL;
    while(n--){
        int t;
        scanf("%d",&t);
        head = addtoList(head,t);
    }
    return head;
}
int main(){
    Node* head = readList();
    head = increasing(head);
    printList(head);
    return 0;
}