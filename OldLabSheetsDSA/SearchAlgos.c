#include <stdio.h>
int LinearSearch(int* arr,int n,int x){
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            return i;
        }
    }
    return -1;
}
int binarySearch(int* arr,int n,int low,int high,int x){
    while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid]==x){
            return mid;
        }else if(arr[mid]<x){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 4;
    printf("%d ",LinearSearch(arr,n,x));
    printf("%d ",binarySearch(arr,n,0,n-1,x));
}