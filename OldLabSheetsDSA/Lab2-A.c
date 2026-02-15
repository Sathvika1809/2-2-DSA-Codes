#include <stdio.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;
int findMedian(Node* head){
    Node* temp = head;
    if(head == NULL){
        return -1;
    }
    int k=0;
    while(temp!=NULL){
        k++;
    }
    Node* temp = head;
    int s = k/2;
        if(k%2 == 1){
            while(s!=0){
                temp= temp->next;
                s--;
            }
            return temp->data;
        }else if(k%2 == 0){
            int s1 = k/2-1;
            while(s1!=0){
                temp= temp->next;
                (s1)--;
            }
            int lower = temp->data;
            temp= temp->next;
            int higher = temp->data;
            int avg = (lower+higher)/2;
            return avg;
        }
    }
   


int main(){
    int n;





    return 0;
}