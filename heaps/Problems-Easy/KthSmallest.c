//TC: O(n*logk) and SC:O(k)//for heapbuild
//Idea is nice like build heap of size k and change roots
//if the rem element is less than the root then change root as we want smallest only and heapify
//the stored will be k smallest num and the largest would be kth smallest number
//so yea its nice i felt:)

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int* arr,int n,int i){
    int largest = i;
    int left = 2*i+1,right=2*i+2;
    if(left<n&&arr[left]>arr[largest]){
        largest = left;
    }
    if(right<n&&arr[right]>arr[largest]){
        largest = right;
    }
    if(largest!=i){
        swap(&arr[largest],&arr[i]);
        heapify(arr,n,largest);
    }
    return;
}

int buildMaxHeap(int* arr,int n,int k){
    for(int i=(k/2)-1;i>=0;i--){
        heapify(arr,k,i);
    }
    for(int i=k+1;i<n;i++){
        if(arr[i]<arr[0]){
            arr[0]=arr[i];
            heapify(arr,k,0);
        }
    }
    return arr[0];
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int k;
    scanf("%d",&k);
    printf("%d",buildMaxHeap(arr,n,k));
    return 0;
}