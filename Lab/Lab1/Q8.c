#include <stdio.h>

void printList(int* arr,int n){
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
void swap(int* a,int* b){
    int temp =*a;
    *a=*b;
    *b=temp;
}
void reverse(int* arr,int i,int j){
   while(i<j){
    swap(&arr[i],&arr[j]);
    i++;
    j--;
   }
}
void rotateLeft(int* arr,int n,int k){
    reverse(arr,0,n-1);
    reverse(arr,0,n-k-1);
    reverse(arr,n-k,n-1);
    printList(arr,n);
}
void rotateRight(int* arr,int n,int k){
    reverse(arr,0,n-1);
    reverse(arr,k,n-1);
    reverse(arr,0,k-1);
    printList(arr,n);
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int D;
    scanf("%d",&D);
    printf("\n");
    int k;
    scanf("%d",&k);
    k=k%n;
    if(D==0){
        rotateLeft(arr,n,k);
    }
    if(D==1){
        rotateRight(arr,n,k);
    }


}