#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;
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
Node* reverse(Node* head){
    if(!head||!(head->next)){
        return head;
    }
    Node* temp = head;
    Node* toBeTail=temp->next;
    temp->next = NULL;
    Node* newHead = reverse(toBeTail);
    toBeTail->next = temp;
    return newHead;
}
Node* getMedian(Node* head){
    if(!head||!(head->next)){
        return head;
    }
    Node* fast = head->next;
    Node* slow = head;
    while(fast&&fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
  return slow;
}
Node* readList(){
    int n;
    scanf("%d",&n);
    Node* head = NULL;
    while(n--){
        int x;
        scanf("%d",&x);
        head = addtoList(head,x);
    }
    return head;
}
int palindrome(Node* head){
    if(!head&&!(head->next)){
        return 1;
    }
    Node* mid = getMedian(head);
    Node* right = mid->next;
    mid->next = NULL;
    right = reverse(right);
    Node* curr1 = head;
    Node* curr2 = right;
    int res = 1;
    while(curr2){
        if(curr1->data!=curr2->data){
            res=0;
            break;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    right = reverse(right);
    mid->next = right;
    return res;
    
}
int main(){
    Node* head = readList();
    if(palindrome(head)){
        printf("True\n");
    }else{
        printf("False\n");
    }
   return 0; 
}
