#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode* next;

};

struct ListNode* mergeTwoLists(struct ListNode* a,struct ListNode* b){
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;
    while(a!=NULL && b!=NULL){
        if(a->val <= b->val){
           tail->next = a;
           a = a->next;
        }else{
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    while(a!=NULL){
        tail->next = a;
    }
    while(b!=NULL){
        tail->next = b;
    }
    return dummy.next;
}

struct ListNode* solve(struct ListNode** lists,int left,int right){
    if(left>right){
        return NULL;
    }
    if(left == right){
        return lists[left];
    }
    int mid = left+(right-left)/2;

    struct ListNode* l1 = solve(lists,left,mid);
    struct ListNode* l2 = solve(lists,mid+1,right);


    return mergeTwoLists(l1,l2);
}

struct ListNode* mergeKLists(struct ListNode** lists,int listsSize){
    if(listsSize == 0){
        return NULL;
    }
    return solve(lists,0,listsSize-1);
}