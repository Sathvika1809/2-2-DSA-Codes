#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
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
}
Node* getMedian(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast= fast->next->next;
    }
    return slow;
}
Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    while(curr !=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
//Recursive reverse
Node* reverseRec(Node* head){
    if(!head ||!head->next){
        return head;
    }
    Node* curr = head;
    Node* toBetail = curr->next;
    curr->next = NULL;
    Node* newHead = reverseRec(toBetail);
    toBetail->next = curr;
    return newHead;
}
int palindrome(Node* head){
    if(head == NULL||head->next==NULL){
        return 1;
    }
    Node* curr = head;
    Node* mid = getMedian(head);
    Node* temp = reverseRec(mid->next);
    mid->next = NULL;
    Node* second = temp;
    while(temp!=NULL){
        if(temp->data != curr->data){
            return 0;
        }
        curr= curr->next;
        temp=temp->next;
    }
    mid->next = reverse(second);
    return TRUE;
    
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
        Node* curr = head;
        while(curr->next!=NULL){
            curr= curr->next;
        }
        curr->next = newNode;
    }
    return head;
}
Node* readList(){
    int N;
    printf("Enter the number of nodes: ");
    scanf("%d",&N);
    Node* head = NULL;
    while(N--){
        int x;
        scanf("%d",&x);
        head = addtoList(head,x);
    }
    return head;
}
Node* addNode(Node* head,Node* newNode){
    Node* temp = head;
    if(head == NULL){
        head = newNode;
    }
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return temp;
}

int main(){
    Node* head = readList();
    int x = palindrome(head);
    if(x==1){
        printf("True");
    }else{
        printf("False");
    }
return 0;
}