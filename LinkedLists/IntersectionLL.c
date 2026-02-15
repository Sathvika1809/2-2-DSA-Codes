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
    return head;
}
//Brute force
// Node* intersect(Node* head1,Node* head2){
//     while(head2!=NULL){
//         Node* temp = head1;
//         while(temp!=NULL){
//             if(temp == head2){
//                 return head2;
//             }
//             temp = temp->next;
//         }
//         head2 =head2->next;
//     }
//     return NULL;
// }
//
Node* getIntersectionPt(int diff,Node* head1,Node* head2){
    Node* curr = head1;
    Node* temp = head2;
    for(int i=0;i<diff;i++){
        if(curr == NULL){
            return NULL;
        }
        curr = curr->next;
    }
    while(curr!=NULL &&temp!=NULL){
        if(curr == temp){
            return temp;
        }
        curr = curr->next;
        temp = temp->next;
    }
    return NULL;

}
Node* intersect(Node* head1,Node* head2){
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    int d = 0;
    if(len1>len2){
        d = len1-len2;
        return getIntersectionPt(d,head1,head2);
    }else{
        d = len2 - len1;
        return getIntersectionPt(d,head2,head1);
    }
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
    Node* head1 = readList();
    Node* head2 = readList();
    Node* result = intersect(head1,head2);
    if(result == NULL){
        printf("-1\n");
    }else{
        printf("%d ",result->data);
        printf("\n");
    }

    return 0;
}