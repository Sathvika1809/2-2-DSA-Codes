#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
typedef struct Node_t{
    int val;
    int i;
    int j;
}Node;
int max(int a,int b){
    return a>b?a:b;
}
void swap(Node* a,Node* b){
    return a.val<=b.val;
}
void heapifyUp(int* heap,int* sz,int idx){
    //minheap
}
int main(){
    int k;
    scanf("%d",&k);
    int N[k];
    int a[k][10000];
    for(int i=0;i<k;i++){
        scanf("%d",&N[i]);
        for(int j=0;j<N[i];j++){
            scanf("%d",&a[i][j]);
        }
    }
    Node heap[MAX];
    int sz = 0;
    int curr_max = -10000;
    for(int i=0;i<k;i++){
        curr_max = max(curr_max,a[i][0]);
    }
    for(int i=0;i<k;i++){
        insert(heap,&sz,a[i][0],i,0);
    }
    int l = heap[0].val,r = curr_max;
    int ans = curr_max - heap[0].val;
    while(1){
        Node cur= pullRoot(heap,&sz);
        int ni = cur.i;
        int nj = cur.j;
        nj++;
        if(nj>=N[ni])break;
        insert(heap,&sz,a[ni][nj],ni,nj);
        curr_max = max(curr_max,a[ni][nj]);
        int curRange = curr_max - heap[0].val;
        if(curRange<ans||(curRange==ans)&&(heap[0].val<l)){
            ans = curRange;
            l = heap[0].val;
            r = curr_max;
        }
    }
    printf("%d %d",l,r);

    return 0;
}