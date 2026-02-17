#include <stdio.h>
void swap(int* a,int* b){
    int temp =*a;
    *a=*b;
    *b = temp;
}
// void sort(int* arr,int l,int r,int n){
//     if(r>n-1) r=n-1;
//     int swapped = 0;
//     do{
//       swapped = 0;
//       for(int i=l;i<r;i++){
//         if(arr[i]>arr[i+1]){
//             int t = arr[i];
//             arr[i]=arr[i+1];
//             arr[i+1] = t;
//             swapped = 1;
//         }
//     }
// }while(swapped == 1);

// }
//In terms of for loop
void sort(int* arr,int l,int r,int n){
    if(r>n-1)r = n-1;
    int swapped = 0;
    for(int i=l;i<r;i++){
        for(int j=l;j<=r-(i-l)-1;j++){
            if(arr[j]>arr[j+1]){
                int t = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
                swapped = 1;
            }
        }

        if(!swapped){
            break;
        }
    }
}
// void solve(int* arr,int n){
//     int i=0;
//     int curr = 1;
//     while(i<n){
//         sort(arr,i,curr+i-1,n);
//         i+=curr;
//         curr++;
//     }
// }
void solve(int* arr,int n){
    int i=0;
    int curr = 1;
    while(i<n){
        sort(arr,i,curr+i,n);
        i+=curr;
        curr++;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    solve(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}