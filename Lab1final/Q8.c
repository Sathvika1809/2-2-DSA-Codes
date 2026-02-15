#include <stdio.h>
// void swap(int* a,int* b){
//     int temp =*a;
//     *a =*b;
//     *b = temp;
// }
void reverse(int* arr,int l,int r){
    while(l<r){
        int temp = arr[l];
        arr[l]=arr[r];
        arr[r]=temp;
        l++;
        r--;
    }
}
void printList(int* arr,int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
void rotateLeft(int* arr,int n,int k){
    reverse(arr,0,n-1);
    reverse(arr,n-k,n-1);
    reverse(arr,0,n-k-1);
    printList(arr,n);
}
void rotateRight(int* arr,int n,int k){
    reverse(arr,0,n-1);
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);
    printList(arr,n);
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter D =0 for left and 1 for right: ");
    int D;
    scanf("%d",&D);
    int k;
    printf("Enter the value of k: ");
    scanf("%d",&k);
    k=k%n;
    if(D==0){
        rotateLeft(arr,n,k);
    }
    else if(D==1){
        rotateRight(arr,n,k);
    }else{
        printf("Invalid direction");
    }

    return 0;
}