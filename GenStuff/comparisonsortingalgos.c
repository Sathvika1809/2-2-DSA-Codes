#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void mergesort(int* arr,int n);
int* merge(int* a,int alen,int* b,int blen);
int* mergesortHelper(int* arr,int l,int r);
void insertionsort(int* arr,int n);
void bubblesort(int* arr,int n);
void selectionsort(int* arr,int n);
void printList(int* arr,int n){
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}
void swap(int* a,int* b){
    int temp =*a;
    *a=*b;
    *b=temp;
    return;
}
int* merge(int* a,int alen,int* b,int blen){
    int* arr = calloc(alen+blen,sizeof(int));
    int l=0,r=0,k=0;
    while(l<alen&&r<blen){
        if(a[l]<=b[r]){
            arr[k++]=a[l++];
        }else{
            arr[k++]=b[r++];
        }
    }
    while(l<alen){
        arr[k++]=a[l++];
    }
    while(r<blen){
        arr[k++]=b[r++];
    }
    return arr;
}
int* mergesortHelper(int* arr,int l,int r){
    if(l==r)return arr;
        int m = l+(r-l)/2;
        int* left = mergesortHelper(arr,l,m);
        int* right = mergesortHelper(arr,m+1,r);
        return merge(int* left,m-l+1,int* right,r-m);
}
void mergesort(int* arr,int n){
   arr = mergesortHelper(arr,0,n-1);
}
void bubblesort(int* arr,int n){
    for(int i=0;i<n;i++){
        int swapped=0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1] = temp;
                swapped=1;
            }
        }
        if(!swapped){
            break;
        }
    }
}
void bubblesortdo(int* arr,int n){
    int swapped = 0;
    do{
        swapped = 0;
        for(int j=0;j<n;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped=1;
            }
        }
    }while(swapped=1);
}
void insertionsort(int* arr,int n){
    for(int i=0;i<n-1;i++){
        int j=i+1;
        int val = arr[j];
        while(j>0 && val<arr[j-1]){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j]=val;
    }
    return;
}
void selectionsort(int* arr,int n){
    for(int i=0;i<n;i++){
        int min = arr[i];
        int minIdx=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<min){
                min = arr[j];
                minIdx = j;
            }
        }
        swap(&arr[i],&arr[minIdx]);
    }
    return;
}
