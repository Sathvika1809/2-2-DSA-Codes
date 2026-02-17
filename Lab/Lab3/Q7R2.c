#include <stdio.h>
#include <stdlib.h>
void printList(int* arr,int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void sort(int* arr,int l,int r,int n){
    if(r>n-1)r=n-1;
    int swapped=0;
    do{
        swapped = 0;
        for(int j=l;j<r;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                swapped =1;
            }
        }

    }while(swapped==1);
}


void groupSort(int* arr,int n){
    int i=0;
    int curr = 1;
    while(i<n){
        sort(arr,i,i+curr-1,n);
        i+=curr;
        curr++;
    }
    return;
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    groupSort(arr,n);
    printList(arr,n);
    return 0;
}