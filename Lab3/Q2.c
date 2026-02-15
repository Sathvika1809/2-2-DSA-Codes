#include <stdio.h>

//  void swap(int* a,int* b){
//     int temp =*a;
//     *a =*b;
//     *b = temp;
// }
int findMax(int* arr,int n){
    int low = 1,high = n-2;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1]){
            return mid;
        }
        else if(arr[mid]<arr[mid+1]){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return -1;
}
// void bubble(int* arr,int n){
//     for(int i=0;i<n;i++){
//         int didSwap = 0;
//         for(int j=0;j<n-i-1;j++){
//             if(arr[j]>arr[j+1]){
//                 swap(&arr[j],&arr[j+1]);
//                 didSwap = 1;
//             }
//         }
//         if(!didSwap){
//             break;
//         }
//     }
// }
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int a = arr[0];
    int b = arr[n-1];
    //bubble(arr,n);
    printf("%d ",findMax(arr,n));
}