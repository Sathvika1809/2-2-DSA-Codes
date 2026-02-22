#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct Pair{
    int val;
    int idx;
}Pair;
int cmp(Pair p1,Pair p2){
    return p1.val<p2.val;
}
void merge(Pair* arr,int l,int m,int r){
   Pair L[m-l+1];
   Pair R[r-m];
    for(int i=l;i<=m;i++){
        L[i-l]=arr[i];
    }
    for(int i=m+1;i<=r;i++){
        R[i-m-1] = arr[i];
    }
    int i=0,j=0,k=l;
    while(i<m-l+1&&j<r-m){
        if(cmp(L[i],R[j])){
            arr[k++]=L[i++];
        }else{
            arr[k++]=R[j++];
        }
    }
    while(i<m-l+1){
        arr[k++]=L[i++];
    }
    while(j<r-m){
        arr[k++]=R[j++];
    }

    return;
}
void mergesort(Pair* arr,int lo,int hi){
    if(lo<hi){
        int mid = lo+(hi-lo)/2;
        mergesort(arr,lo,mid);
        mergesort(arr,mid+1,hi);
        merge(arr,lo,mid,hi);
    }
    return;
}

void mergesortHelper(Pair* arr,int n){
    mergesort(arr,0,n-1);
}
int main(){
    int n,x;
    scanf("%d %d",&n,&x);
    Pair arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i].val);
        arr[i].idx = i;
    }
    int left = 0,right = n-1;
    mergesortHelper(arr,n);
    int fnd=0;
    while(left<right){
        if(arr[left].val+arr[right].val==x){
            fnd = 1;
            printf("%d %d\n",arr[left].idx+1,arr[right].idx+1);
            break;
        }else if(arr[left].val+arr[right].val<x){
            left++;
        }else{
            right--;
        }
    }
    if(!fnd){
        printf("IMPOSSIBLE\n");
    }
    return 0;
}