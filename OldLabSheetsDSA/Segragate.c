#include <stdio.h>
#include <stdlib.h>
type_def struct Node_t{
    int data;
    struct Node_t* next;
}Node;

void printList(Node* head);
Node* modifyList(Node* head);
Node* readList();
Node* addNode(Node* head,Node* newNode);
Node* addtoList(Node* head,int temp);
Node* createNode(int val);

Node* addNode(Node* head,Node* newNode){
    if(head == NULL){
        head = newNode;
    }else{
        Node* curr = head;
        while(curr->next!=NULL){
            curr = curr->next;
        }
        curr->next = newNode;
    }
    return head;
}
void printList(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
Node* modifyList(Node* head){
    Node* curr = head;
    Node* odd =NULL;
    Node* even = NULL;
    while(curr!=NULL){
        Node* toGo = curr->next;
        curr->next = NULL;
        if((curr->data)%2 == 1){
            odd = addNode(odd,curr);
        }else {
            even = addNode(even,curr);
        }
        curr = toGo;
    }
    if(!even){
        return odd;
    }
    


}
Node* createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;

}
Node* addtoList(Node* head,int temp){
    if(head == NULL){
        head = createNode(temp);
    }
    Node* curr = head;
    while(curr->next!=NULL){
        curr= curr->next;
    }
    curr->next = createNode(temp);
    return head;
}
Node* readList(){
    int n;
    printf("Enter the number of Nodes:");
    scanf("%d",&n);
    Node* head = NULL;
    while(n--){
        int temp;
        scanf("%d",&temp);
        Node* head = addtoList(head,temp);
    }

}
int main(){
Node* list = readList();
list = modifyList(list);
printList(list);

    return 0;
}