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
    for(int i=k;i<n;i++){
        if(arr[i]<arr[0]){
            arr[0]=arr[i];
            heapify(arr,k,0);
        }
    }
    return arr[0];
}
//Key is we want to Kth largest and Kth Smallest without sorting Fully
//sorting ->O(nlogn) but QuickSelect-O(n)avg time
int partition(int* arr,int l,int r){
    int pivot = arr[r];
    int i=l;
    for(int j=l;j<r;j++){
        if(arr[j]<=pivot){
            swap(&arr[i],&arr[j]);
            i++;
        }
    }
    swap(&arr[i],&arr[r]);
    return i;
}
int QuickSelect(int* arr,int l,int r,int k){
    if(l<=r){
        int pivotIdx = partition(arr,l,r);
        if(pivotIdx == k) return arr[pivotIdx];
        else if(pivotIdx > k) return QuickSelect(arr,l,pivotIdx-1,k);
        //Kth largest means ntg convert idx to n-k instead of k
        //2nd largest means 4th posn correct element
        else return QuickSelect(arr,pivotIdx+1,r,k);
        //We just look on the side where idx=k(sorted posn) on one side

    }
    return -1;
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
    printf("%d\n",buildMaxHeap(arr,n,k));
    int l=0,r=n-1;
    int ans=QuickSelect(arr,l,r,n-k);//Kth largest
    //2nd largest in n=6 means 4th smallest element
    //For kth smallest call
    //ans = Quickselect(arr,l,r,k-1);
    
    //Dont use heap and quickselect on one go u are using the changed array just wrote for
    //referring other mthd
    //Both are fine
    printf("%d\n",ans);
    return 0;
}
//Using QuickSelect
//To find Kth smallest Element,Kth LARGEST Element
