#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;
int countNodes(Node* head){
    if(head == NULL){
        return 0;
    }
    if(head->next == NULL){
        return 1;
    }
    Node* temp = head;
    int cnt = 0;
    while(temp!=head){
        temp = temp->next;
        cnt++;
    }
    return cnt;
    
}
int main(){


    return 0;
}