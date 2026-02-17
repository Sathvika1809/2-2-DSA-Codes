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
    if(head == NULL){
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
Node* readList(){
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    Node* head = NULL;
    while(n--){
        int x;
        scanf("%d",&x);
        head = addtoList(head,x);
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
Node* merge(Node* even,Node* odd){
    if(even==NULL){
        return odd;
    } 
    if(odd==NULL){
        return even;
    }
    Node* temp = even;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = odd;
    return even;
}
Node* segregate(Node* head){
    Node* odd = NULL;
    Node* even = NULL;
    Node* temp = head;
    while(temp!=NULL){
        Node* nextTemp = temp->next;
        temp->next = NULL;
        if(temp->data%2==0){
            even = addNode(even,temp);
        }else{
            odd = addNode(odd,temp);
        }
        temp=nextTemp;
    }
    merge(even,odd);
}
int main(){
    Node* head = readList();
    head = segregate(head);
    printList(head);

}