#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;
void maxFreq(Node* head){
    Node* curr = head->next;
    int prev = head->data;
    int ans = head->data;
    int cf = 1;
    int maxcf = 1;
    while(curr){
        if(curr->data == prev){
            cf++;
            if(cf>maxcf){
                maxcf = cf;
                ans = curr->data;
            }
        }else{
            cf = 1;
            prev = curr->data;
        }
        curr = curr->next;
    }
    if(maxcf > 1){
        printf("%d ",ans);
    }else{
        printf("-1\n");
    }
return;
}
void printList(Node* head){
    Node* temp = head;
    while(temp){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}
Node* createNode(int val){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
Node* addtoList(Node* head,int val){
    Node* newNode = createNode(val);
    if(!head) return newNode;
    Node* temp = head;
    while(temp){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
Node* reverse(Node* head){
    Node* temp = head;
    Node* prev= NULL;
    Node* next = NULL;
    while(temp->next!=NULL){
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = temp->next;
    }
    return head;
}
Node* insertAtHead(Node* head,int val){
    Node* newNode = createNode(val);
    if(head==NULL){
        return newNode;
    }
    newNode->next = head;
    return newNode;
}
Node* readList(int n){
    Node* head = NULL;
    while(n--){
        char temp;
        scanf(" %c",&temp);
        head = insertAtHead(head,temp-'0');
    }
    return head;
    //Optimal - O(n) reverse this for normal readList
}
Node* readBigInt(int n){
    Node* head = NULL;
    while(n--){
        char temp;
        scanf("%c",&temp);
        head = addtoList(head,temp-'0');
    }
    return head;
}
void addBigInt(){
    int m,n;
    scanf("%d",&m);
    Node* num1 = readBigInt(m);
    scanf("%d",&n);
    Node* num2 = readBigInt(n);
    num1 = reverse(num1);
    num2 = reverse(num2);
    Node* ans = NULL;
    int carry = 0;
    Node* curr1 = num1;
    Node* curr2 = num2;
    while(curr1 &&curr2){
        int total = curr1->data + curr2->data;
        int val = total%10;
        carry = total/10;
        ans = addtoList(ans,val);
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    while(curr1){
        int total = curr1->data+carry;
        ans = addtoList(ans,total%10);
        carry = total/10;
        curr1 = curr1->next;
    }
    while(curr2){
        int total = curr2->data+carry;
        ans = addtoList(ans,total%10);
        carry = total/10;
        curr2 = curr2->next;
    }
    while(carry>0){
        ans = addtoList(ans,carry%10);
        carry/=10;
    }
    ans = reverse(ans);
    printList(ans);

}
void printCommon(Node* h1,Node* h2){
    //assuming the given ll are sorted
    Node* c1 = h1;
    Node* c2 = h2;
    int last = INT_MIN;
    while(c1&&c2){
        if(c1->data == c2->data){
            if(last == c1->data){
                c1 = c1->next;
                c2 =c2->next;
            }else{
                last = c1->data;
                printf("%d ",c1->data);
                c1 = c1->next;
                c2 = c2->next;
            }
        }else if(c1->data < c2->data){
            c1 = c1->next;
        }else{
            c2 = c2->next;
        }
    }
    printf("\n");
    return;
}

int main(){
 addBigInt();




    return 0;
}